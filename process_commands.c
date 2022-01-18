
#include "minishell.h"


void	ft_process_commands(t_command *cmds, t_builtin *bt, char **envp, int nbcmd)
{
	int	pip[2];
	int	i;
	(void)cmds;
	(void)envp;
	int	j;
	
	ft_process_redirect(cmds, nbcmd);

	i = 0;
	while (i < nbcmd)
	{
		printf("[pre] %d fdin %d fdout %d  ", i, cmds[i].fdin, cmds[i].fdout);

		j = 0;
		while (j < cmds[i].nbarg)
		{
			printf("_%s_  ", cmds[i].args[j]);
			j++;
		}
		i++;
		printf("\n");
		
	}


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


	i = 0;
	while (i < nbcmd)
	{
		printf("[cmd] %d fdin %d fdout %d  ", i, cmds[i].fdin, cmds[i].fdout);

		j = 0;
		while (j < cmds[i].nbarg)
		{
			printf("_%s_  ", cmds[i].args[j]);
			j++;
		}
		i++;
		printf("\n");
		
	}


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

			j = 0;
			while (j < bt->nb)
			{
				if (ft_strncmp(cmds[i].args[0], bt->cmds[j]->name, ft_strlen(bt->cmds[j]->name + 1)) == 0)
				{
					bt->cmds[j]->function(cmds[i], envp);
					break ;
				}
				j++;
			}
			if (j == bt->nb)
				builtin_default(cmds[i], envp);
			exit(1);
		}
		i++;
	}

	int status;

	i = 0;
	while (i < nbcmd)
	{
		waitpid(pids[i], &status, 0);
		i++;
	}
	free(pids);

	i = 0;
	while (i < nbcmd)
	{
		if(cmds[i].fdin != 0)
			close(cmds[i].fdin);
		if(cmds[i].fdout != 1)
			close(cmds[i].fdout);		
		i++;
	}
}