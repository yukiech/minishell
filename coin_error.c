/* ************************************************************************** */
/*                                                                            */
/*                                        __                        __        */
/*                                    ___( o)>      CoinCoin ?    <(o )___    */
/*                                    \ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/22 11:20:04 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	coin_error2(char *err1, char *err2)
{
	ft_putstr_fd("CoinCoinShell: ", 2);
	ft_putstr_fd(err1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err2, 2);
	ft_putendl_fd("", 2);
	g_exit_stat = 1;
}

void	coin_error_errno(char *err1)
{
	char	*err2;

	err2 = strerror(errno);
	ft_putstr_fd("CoinCoinShell: ", 2);
	ft_putstr_fd(err1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err2, 2);
	ft_putendl_fd("", 2);
	g_exit_stat = 1;
	free(err2);
}


void	coin_error3(char *err1, char *err2, char *err3)
{
	ft_putstr_fd("CoinCoinShell: ", 2);
	ft_putstr_fd(err1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err2, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err3, 2);
	ft_putendl_fd("", 2);
	g_exit_stat = 1;
}

void	coin_error3m(char *err1, char *err2, char *err3)
{
	ft_putstr_fd("CoinCoinShell: ", 2);
	ft_putstr_fd(err1, 2);
	ft_putstr_fd(err2, 2);
	ft_putstr_fd(err3, 2);
	ft_putendl_fd("", 2);
	g_exit_stat = 1;
}
