/* ************************************************************************** */
/*                                                                            */
/*                                        __                        __        */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/20 18:32:06 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(t_command cmd, char **envp)
{
	char	pwd[PATH_MAX];

	(void)cmd;
	(void)envp;
	if (getcwd(pwd, PATH_MAX))
	{
		ft_putendl_fd(pwd, 1);
	}
}
