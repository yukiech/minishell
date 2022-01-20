#include "minishell.h"



void	builtin_unset(t_command cmd, char **envp)
{
	int	i;
	char	*var_temp;

	i = 0;
	var_temp = cmd.args[1];
	while(envp[i])
	{
		if (ft_strncmp(envp[i], var_temp, ft_strlen(var_temp)) == 0)
		{
			while (envp[i + 1])
			{
				envp[i] = envp[i + 1];
				i++;
			}
			envp[i] = NULL;
		}
		i++;
	}
}
