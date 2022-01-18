
#include "minishell.h"

void	ft_process_fds(t_command *cmds, int nbcmd)
{
	int	pip[2];
	int	i;

	i = 0;
	while (i < nbcmd - 1)
	{
		pipe(pip);
		if (cmds[i].fdout == -1)
			cmds[i].fdout = pip[1];
		else
			close(pip[1]);

		if (cmds[i + 1].fdin == -1)
			cmds[i + 1].fdin = pip[0];
		else
			close(pip[0]);
		i++;		
	}
}