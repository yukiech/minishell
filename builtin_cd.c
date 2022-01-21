/* ************************************************************************** */
/*                                                                            */
/*   CoinCoinShell.c                      __                        __        */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/20 22:27:59 by ahuber           ###   ########.fr       */
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
			perror("CoinCoinShell: cd");
	}
	else
	{
		temp = ft_get_env(envp, "HOME=");
		if (temp != NULL)
		{
			error = chdir(temp);
			if (error == -1)
				perror("CoinCoinShell: cd");
			if (temp != NULL)
				free(temp);
		}
		else
			coin_error2("cd", "HOME not set");
	}
}
