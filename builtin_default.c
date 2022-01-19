#include "minishell.h"

static void	free_default(char **path_splitted)
{
	int	i;

	i = 0;
	while (path_splitted[i])
	{
		free(path_splitted[i]);
		i++;
	}
	i = 0;
	while (path_splitted_cmd[i])
	{
		free(path_splitted_cmd[i]);
		i++;
	}
	free(path_splitted);
	free(path_splitted_cmd);
}

static int	test_and_exec_cmd(char **path_splitted, t_command cmd, char **envp)
{
	int	i;

	i = 0;
	while (path_splitted[i])
	{
		if ((access(path_splitted[i], F_OK)) == 0)
		{
			execve(path_splitted[i], cmd.args, envp);
			return(0);
		}
		else
			i++;
	}

	return (1);
}

void	builtin_default(t_command cmd, char **envp)
{
	char	*path;
	char	**path_splitted;
	char	**path_splitted_cmd;
	char	*add_cmd;
	int	i;
	
	i = 0;
	path = getenv("PATH");
	path_splitted = ft_split(path, ':');
	add_cmd = ft_strjoin("/", cmd.args[0]);
	while (path_splitted[i] != NULL)
	{
		char 	*temp;	
		temp = ft_strjoin(path_splitted[i], add_cmd);
	//	free(path_splitted[i]);
		path_splitted_cmd[i] = temp;
		i++;
	
	}
	test_and_exec_cmd(path_splitted_cmd, cmd, envp);
	free_default(path_splitted, path_splitted_cmd);
}
