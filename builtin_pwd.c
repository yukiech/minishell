#include "minishell.h"

void	builtin_pwd(t_command cmd, char **envp)
{
	(void)cmd;
	(void)envp;

	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX))
	{
		write(1, &pwd, ft_strlen(pwd));
		write(1, "\n", 1);
	}
}
