/* ************************************************************************** */
/*                                                                            */
/*   CoinCoinShell.c                      __                        __        */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/21 17:03:43 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_cd(t_command cmd, char **envp)
{
	int		error;
	int		i;
	char	*temp;

	i = 1;
	if (cmd.nbarg >= 2)
	{
		error = chdir(cmd.args[i]);
		if (error == -1)
			printf("CoinCoinShell: cd: %s: No such file or directory",
				cmd.args[1]);
	}
	else
	{
		temp = ft_get_env(envp, "HOME=");
		error = chdir(temp);
		free(temp);
	}
}
