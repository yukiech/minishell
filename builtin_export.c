#include "minishell.h"

static int	search_for_equal(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return(0);
}

void	builtin_export(t_command cmd, char **envp)
{
	int	i;
	int	exists;
	char	*new_var;

	new_var = ft_strdup(cmd.args[1]);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], new_var, search_for_equal(new_var)) == 0)
		{
			exists = 1;
			break ;
		}
		i++;
	}
	if (exists != 1)
	{
		envp[i] = new_var;
		envp[i + 1] = NULL;
	}
	else
		envp[i] = new_var;
}
