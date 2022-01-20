#include "minishell.h"

void	builtin_cd(t_command cmd, char **envp)
{
	int		error;
	int		i;
	char	*temp;

	i = 1;
	if (cmd.nbarg >= 2)
	{
		error = chdir(cmd.args[i]);
		if (error == -1)
			perror("cd");
	}
	else
	{
		temp = ft_get_env(cmd, envp, "HOME");
		error = chdir(temp);
		free(temp);
	}
}
