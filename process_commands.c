
#include "minishell.h"


void	ft_process_commands(t_command *cmds, t_builtin *bt, char **envp, int nbcmd)
{
	int	i;
	(void)cmds;
	(void)envp;
	int	j;
	
	ft_process_redirect(cmds, nbcmd);


	i = 0;
	while (i < nbcmd)
	{
		printf("cmd %d fdin %d fdout %d  ", i, cmds[i].fdin, cmds[i].fdout);

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
	while (i < nbcmd)
	{
		j = 0;
		while (j < bt->nb)
		{
			if (ft_strncmp(cmds[i].args[0], bt->cmds[j]->name, ft_strlen(bt->cmds[j]->name + 1)) == 0)
			{
				bt->cmds[j]->function(cmds[i], envp);
			}
//			printf("_%s_\n", bt->cmds[i]->name);
//			printf("\n");
			j++;
		}
		i++;
	}
}