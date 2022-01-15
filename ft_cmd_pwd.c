#include "minishell.h"

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
