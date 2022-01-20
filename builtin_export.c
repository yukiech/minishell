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

int	invalid_var(t_command cmd, char **envp)
{
	int	i;
	int	result;
	
	i = 0;
	result = 0;
	if (cmd.args[1][0] == '=' || cmd.args[1][0] == '/')
	{
		printf("bash: export: `%s': not a valid identifier", cmd.args[1]);
		result = 1;
	}
	while (cmd.args[1][i] != '=')
	{
		if (cmd.args[1][i] == '/')
		{
			printf("bash: export: `%s': not a valid identifier", cmd.args[1]);
			result = 1;
		}
		i++;
	}
	return (result);
}

void	builtin_export(t_command cmd, char **envp)
{
	int	i;
	int	exists;
	char	*new_var;

	new_var = ft_strdup(cmd.args[1]);
	i = 0;
	if (invalid_var(cmd, envp) == 0)
	{
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
}
