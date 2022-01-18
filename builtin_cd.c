#include "minishell.h"

void	builtin_cd(t_command cmd, char **envp)
{
	(void)cmd;
	(void)envp;
	int		error;
	int		i;
	char	*str;

	str = "CoinCoinShell: cd: No such file or directory\n";
	i = 1;
	error = -1;
	if (cmd.nbarg >= 2)
	{
		while (i < cmd.nbarg)
		{
			if (cmd.args[i] == NULL)
				i++;
			else
				break ;
		}
		error = chdir(cmd.args[i]);
		if (error == -1)
		{
			perror("cd");
		}
	}
	else
	{
		error = chdir(getenv("HOME"));
	}
}
