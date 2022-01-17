#include "minishell.h"

void	builtin_cd(t_command cmd, char **envp)
{
	(void)cmd;
	(void)envp;

	if (cmd.nbarg >= 2)
		printf("[cd] into %d args %s %s  fdout %d\n", cmd.nbarg, cmd.args[0], cmd.args[1], cmd.fdout);
	else
		printf("[cd] pas envie\n");

}