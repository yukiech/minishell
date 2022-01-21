/* ************************************************************************** */
/*                                                                            */
/*   CoinCoinShell.c                      __                        __        */
/*   search_command.c                                   :+:      :+:    :+:   */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/21 08:08:55 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_search_command(t_command *cmds,
			t_builtin *bt, char **envp, int forked)
{
	int	i;
	int	pid;

	i = 0;
	while (i < bt->nb)
	{
		if (ft_strcmp(cmds[0].args[0], bt->cmds[i]->name) == 0)
		{
			bt->cmds[i]->function(cmds[0], envp);
			break ;
		}
		i++;
	}
	if (i == bt->nb && forked == 0)
	{
		pid = fork();
		if (pid == 0)
		{	
			builtin_default(cmds[0], envp);
			ft_free_builtins(bt);
			ft_free_commands(cmds, 1);
			exit(1);
		}
		waitpid(pid, NULL, 0);
	}
	else if (i == bt->nb)
		builtin_default(cmds[0], envp);
}
