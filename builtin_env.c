#include "minishell.h"

void	builtin_env(t_command cmd, char **envp)
{
	(void)cmd;
	int		i;

	i = 0;
	while(envp[i])
	{
		ft_putendl_fd(envp[i], 1);
		i++;
	}
}
