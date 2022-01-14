#include "minishell.h"

void	ft_process_commands(t_commands *cmds, t_builtin *bt, char **envp)
{
	int	i;
	(void)cmds;
	(void)envp;

	i = 0;
	while (i < bt->nb)
	{
		printf("_%s_\n", bt->cmds[i]->name);
		i++;
	}
}