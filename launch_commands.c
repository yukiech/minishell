#include "minishell.h"

static void	ft_single_start(t_command *cmds, t_builtin *bt, char **envp);
static void	ft_fork_commands(t_command *cmds, t_builtin *bt, char **envp, int nbcmd);
static void	ft_wait_forks(int *pids, int nbcmd);
static void	ft_make_dup(int new, int dest);

void	ft_launch_commands(t_command *cmds, t_builtin *bt, char **envp, int nbcmd)
{
	if (nbcmd == 1)
	{
		ft_single_start(cmds, bt, envp);
	}
	else
	{
		ft_fork_commands(cmds, bt, envp, nbcmd);
	}
}

static void	ft_single_start(t_command *cmds, t_builtin *bt, char **envp)
{
	int	bakstdin;
	int bakstdout;

	bakstdin = dup(0);
	bakstdout = dup(0);

	ft_make_dup(cmds[0].fdin, 0);
	ft_make_dup(cmds[0].fdout, 1);
	ft_search_command(cmds, bt, envp, 0);

	ft_make_dup(bakstdin, 0);
	ft_make_dup(bakstdout, 1);
}

static void	ft_fork_commands(t_command *cmds, t_builtin *bt, char **envp, int nbcmd)
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
			ft_make_dup(cmds[i].fdin, 0);
			ft_make_dup(cmds[i].fdout, 1);
			ft_search_command(&cmds[i], bt, envp, 1);
			free(pids);
			ft_free_commands(cmds, nbcmd);
			ft_free_builtins(bt);
			exit(1);
		}
		i++;
	}
	ft_wait_forks(pids, nbcmd);
}

static void	ft_make_dup(int new, int dest)
{
	if (new != dest)
	{
		dup2(new, dest);
		close(new);
	}
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
