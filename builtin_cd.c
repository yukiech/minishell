#include "minishell.h"

void	builtin_cd(t_command *cmd, char **envp)
{
	(void)cmd;
	(void)envp;
	printf("cd\n");
}