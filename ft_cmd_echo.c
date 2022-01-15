// #include "minishell.h"

// Start debugg sans .h

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i + 1 < n)
	{
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

// end debugg sans .h

void	ft_cmd_echo(char **s, int fd)
{
	int	newline;
	int	i;

	newline = 1;
	i = 0;
	if (ft_strncmp(s[i], "-n", 2) == 0)
	{
		newline = 0;
		i++;
	}
	while (s[i])
	{
		ft_putstr_fd(s[i], fd);
		if (s[++i])
			ft_putstr_fd(" ", fd);
	}
	if (newline == 1)
		ft_putstr_fd("\n", fd);
}

// Start main debugg

int	main(int argc, char **argv)
{
	(void)argc;
	char	**s;
	int	i = 0;

	s = malloc(sizeof(char *) * 5);
	while (i++ < 5)
		s[i] = malloc(sizeof(char) * 20);
	s[0] = argv[1];
	s[1] = argv[2];
	s[2] = argv[3];
	s[3] = argv[4];
	s[4] = argv[5];
	ft_cmd_echo(s, 1);
	return (0);
}

// End main debugg
