//#include "minishell.h"

// Start debugg sans .h

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_cmd_pwd(int fd)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX))
	{
		ft_putstr_fd(pwd, fd);
		ft_putstr_fd("\n", fd);
		return (0);
	}
	else
		return (1);
}

// end debugg sans .h

int	ft_cmd_cd(char *args)
{
	int	fd;
	int	error;

	fd = 1;
	error = chdir(args);
	if (error == -1)
	{
		ft_putstr_fd("CoinCoinShell: cd: No such file or directory\n", fd);
		return (1);
	}
	return (0);
}

// Start main debugg
int	main(int argc, char **argv)
{
	(void)argc;
	int	error;
	char	*path = argv[1];

	ft_cmd_pwd(1); // debugg
	error = ft_cmd_cd(path);
	ft_cmd_pwd(1); // debugg
	return(0);
}
// End main debugg
