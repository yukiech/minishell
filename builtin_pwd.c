#include "minishell.h"

void	builtin_pwd(t_command cmd, char **envp)
{
	(void)cmd;
	(void)envp;

	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX))
	{
		ft_putendl_fd(pwd, 1);
	}
}
