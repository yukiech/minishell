#include "minishell.h"

void	builtin_cd(char **args, char **envp)
{
	(void)args;
	(void)envp;
	printf("cd\n");
}