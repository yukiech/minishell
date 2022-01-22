/* ************************************************************************** */
/*                                                                            */
/*                                        __                        __        */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/22 13:43:39 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(t_command cmd, char **envp)
{
	int	newline;
	int	i;

	(void)envp;
	newline = 0;
	i = 1;
	g_exit_stat = 0;
	if (i < cmd.nbarg && ft_strncmp(cmd.args[i], "-n", 2) == 0)
	{
		newline = 1;
		i++;
	}
	while (i < cmd.nbarg)
	{
		ft_putstr_fd(cmd.args[i], 1);
		if (i < cmd.nbarg - 1)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (newline == 0)
		ft_putstr_fd("\n", 1);
	newline = 0;
}
