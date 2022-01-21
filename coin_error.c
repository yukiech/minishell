#include "minishell.h"

void	coin_error2(char *err1, char *err2)
{
	ft_putstr_fd("CoinCoinShell: ", 2);
	ft_putstr_fd(err1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err2, 2);
	ft_putendl_fd("", 2);
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
}

void	coin_error3m(char *err1, char *err2, char *err3)
{
	ft_putstr_fd("CoinCoinShell: ", 2);
	ft_putstr_fd(err1, 2);
	ft_putstr_fd(err2, 2);
	ft_putstr_fd(err3, 2);
	ft_putendl_fd("", 2);
}
