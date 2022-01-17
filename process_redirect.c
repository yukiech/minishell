#include "minishell.h"

static void	ft_free_redirect(t_command *cmd, int todel)
{
	free(cmd->args[todel]);
	cmd->args[todel] = NULL;
	free(cmd->args[todel + 1]);
	cmd->args[todel + 1] = NULL;
}

static void	ft_manage_open(t_command *cmd, int *sign_i, int flags, int dir)
{
	printf("info %d %d\n", cmd->fdin, cmd->fdout);
	if (dir == 0)
	{
		if (cmd->fdin == -1)
			cmd->fdin = open(cmd->args[*sign_i + 1], flags);
		else
			open(cmd->args[*sign_i + 1], flags);
		printf("open _%s_\n", cmd->args[*sign_i + 1]);
	}
	else if (dir == 1)
	{
		if (cmd->fdout == -1)
			cmd->fdout = open(cmd->args[*sign_i + 1], flags, FILE_PERM);
		else
			open(cmd->args[*sign_i + 1], flags, FILE_PERM);
		printf("open _%s_\n", cmd->args[*sign_i + 1]);
	}

	ft_free_redirect(cmd, *sign_i);
	(*sign_i)++;
}

void	ft_process_redirect(t_command *cmds, int nbcmd)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbcmd)
	{
		cmds[i].fdin = -1;
		cmds[i].fdout = -1;
		j = 0;
		while (j + 1 < cmds[i].nbarg)
		{
			if (ft_strncmp(cmds[i].args[j], "<", 2) == 0)
				ft_manage_open(&cmds[i], &j, O_RDONLY, 0);
			else if (ft_strncmp(cmds[i].args[j], ">", 2) == 0)
				ft_manage_open(&cmds[i], &j, O_CREAT | O_WRONLY | O_TRUNC, 1);
			else if (ft_strncmp(cmds[i].args[j], ">>", 3) == 0)
				ft_manage_open(&cmds[i], &j, O_CREAT | O_WRONLY | O_APPEND, 1);
			j++;
		}
		if (cmds[i].fdin == -1)
			cmds[i].fdin = 0;
		if (cmds[i].fdout == -1)
			cmds[i].fdout = 1;
		i++;
	}
}