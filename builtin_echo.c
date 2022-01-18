#include "minishell.h"

void	builtin_echo(t_command cmd, char **envp)
{
	(void)cmd;
	(void)envp;
	int	newline;
	int	i;

	newline = 0;
	i = 1;
	if (i < cmd.nbarg && ft_strncmp(cmd.args[i], "-n", 2) == 0)
	{
		newline = 1;
		i++;
	}
	while (i < cmd.nbarg)
	{
		ft_putstr_fd(cmd.args[i], 1);
		if (i < cmd.nbarg - 1)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (newline == 0)
		ft_putstr_fd("\n", 1);
	newline = 0;
}
