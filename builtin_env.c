#include "minishell.h"

void	builtin_env(t_command cmd, char **envp)
{
	(void)cmd;
	int		i;

	i = 0;
	while(envp[i])
	{
		ft_putstr_fd(envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
