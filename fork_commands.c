
#include "minishell.h"

static void	ft_wait_forks(int *pids, int nbcmd);

void	ft_fork_commands(t_command *cmds, t_builtin *bt, char **envp, int nbcmd)
{
	int	i;
	int	*pids;

	pids = ft_calloc(nbcmd, sizeof(int));

	i = 0;
	while (i < nbcmd)
	{
		pids[i] = fork();

		if (pids[i] == 0)
		{
			dup2(cmds[i].fdin, 0);
			dup2(cmds[i].fdout, 1);
			close(cmds[i].fdin);
			close(cmds[i].fdout);

			ft_start_command(cmds[i], bt, envp);

			free(pids);
			ft_free_commands(cmds, nbcmd);
			ft_free_builtins(bt);
			exit(1);
		}
		i++;
	}
	ft_wait_forks(pids, nbcmd);
}

static void	ft_wait_forks(int *pids, int nbcmd)
{
	int	i;
	int status;

	i = 0;
	while (i < nbcmd)
	{
		waitpid(pids[i], &status, 0);
		i++;
	}
	free(pids);
}
