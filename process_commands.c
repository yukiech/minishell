/* ************************************************************************** */
/*                                                                            */
/*                                        __                        __        */
/*                                    ___( o)>      CoinCoin ?    <(o )___    */
/*                                    \ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/21 17:41:50 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_process_commands(t_command *cmds,
			t_builtin *bt, char **envp, int nbcmd)
{
	int	i;
//	int	j;

	ft_process_redirect(cmds, nbcmd);
	if (cmds[0].fdin == -1)
		cmds[0].fdin = 0;
	if (cmds[nbcmd - 1].fdout == -1)
		cmds[nbcmd - 1].fdout = 1;

//	process_quote(cmds, nbcmd);
	process_dollar(cmds, envp, nbcmd);
/*	i = 0;
	while (i < nbcmd)
	{
		printf("[pre] %d fdin %d fdout %d  ", i, cmds[i].fdin, cmds[i].fdout);
		j = 0;
		while (j < cmds[i].nbarg)
		{
			printf("_%s_  ", cmds[i].args[j]);
			j++;
		}
		i++;
		printf("\n");
	}*/
	ft_process_fds(cmds, nbcmd);
/*	i = 0;
	while (i < nbcmd)
	{
		printf("[cmd] %d fdin %d fdout %d  ", i, cmds[i].fdin, cmds[i].fdout);
		j = 0;
		while (j < cmds[i].nbarg)
		{
			printf("_%s_  ", cmds[i].args[j]);
			j++;
		}
		i++;
		printf("\n");
	}*/
	ft_launch_commands(cmds, bt, envp, nbcmd);
	i = 0;
	while (i < nbcmd)
	{
		if (cmds[i].fdin != 0)
			close(cmds[i].fdin);
		if (cmds[i].fdout != 1)
			close(cmds[i].fdout);
		i++;
	}
	ft_free_commands(cmds, nbcmd);
}
