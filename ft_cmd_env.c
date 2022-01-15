//#include "minishell.h"

// start debugg sans .h

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

// end debugg sans .h

void	ft_cmd_env(int fd, char **envp)
{
	int	i;

	i = 0;

	while(envp[i])
	{
		ft_putstr_fd(envp[i], fd);
		write(fd, "\n", 1);
		i++;
	}
}

// start main debugg

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	int fd = 1;

		ft_cmd_env(fd, envp);
}

// end main debugg
