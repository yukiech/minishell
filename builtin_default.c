#include "minishell.h"

void	builtin_default(t_command cmd, char **envp)
{
	(void)cmd;
	(void)envp;

	printf("Default cmd : %s\n", cmd.args[0]);
}
