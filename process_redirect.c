/* ************************************************************************** */
/*                                                                            */
/*   CoinCoinShell.c                      __                        __        */
/*                                    ___( o)>      CoinCoin ?    <(o )___    */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/20 16:49:18 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_manage_open(t_command *cmd, int *sign_i, int flags, int dir);
static void	ft_concat_file(t_command *cmd, char *filename, int flags);
static void	ft_heredoc(t_command *cmd, int *sign_i);
static void	ft_free_redirect(t_command *cmd, int todel);

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
			else if (ft_strncmp(cmds[i].args[j], "<<", 3) == 0)
				ft_heredoc(&cmds[i], &j);
			j++;
		}
		i++;
	}
	if (cmds[0].fdin == -1)
		cmds[0].fdin = 0;
	if (cmds[nbcmd - 1].fdout == -1)
		cmds[nbcmd - 1].fdout = 1;
}

static void	ft_manage_open(t_command *cmd, int *sign_i, int flags, int dir)
{
	printf("info %d %d\n", cmd->fdin, cmd->fdout);
	if (dir == 0)
	{
		if (cmd->fdin == -1)
			cmd->fdin = open(cmd->args[*sign_i + 1], flags);
		else
			ft_concat_file(cmd, cmd->args[*sign_i + 1], flags);
		printf("[open] _%s_\n", cmd->args[*sign_i + 1]);
	}
	else if (dir == 1)
	{
		if (cmd->fdout != -1)
			close(cmd->fdout);
		cmd->fdout = open(cmd->args[*sign_i + 1], flags, FILE_PERM);
		printf("[open] _%s_\n", cmd->args[*sign_i + 1]);
	}
	ft_free_redirect(cmd, *sign_i);
	(*sign_i)--;
}

static void	ft_concat_file(t_command *cmd, char *filename, int flags)
{
	int		pip[2];
	char	*line;

	pipe(pip);
	line = get_next_line(cmd->fdin);
	while (line != NULL)
	{
		ft_putstr_fd(line, pip[1]);
		free(line);
		line = get_next_line(cmd->fdin);
	}
	close(cmd->fdin);
	cmd->fdin = open(filename, flags);
	line = get_next_line(cmd->fdin);
	while (line != NULL)
	{
		ft_putstr_fd(line, pip[1]);
		free(line);
		line = get_next_line(cmd->fdin);
	}
	close(cmd->fdin);
	close(pip[1]);
	cmd->fdin = pip[0];		
}

static void	ft_heredoc(t_command *cmd, int *sign_i)
{
	int		pip[2];
	char	*line;

	pipe(pip);
	line = NULL;
	while (1 == 1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		line[ft_strlen(line) - 1] = '\0';
		if (ft_strncmp(line, cmd->args[*sign_i + 1],
				ft_strlen(cmd->args[*sign_i + 1]) + 1) == 0)
			break ;
		ft_putendl_fd(line, pip[1]);
		free(line);
	}
	if (line != NULL)
		free(line);
	close(pip[1]);
	if (cmd->fdin != -1)
		close(cmd->fdin);
	cmd->fdin = pip[0];
	ft_free_redirect(cmd, *sign_i);
}

static void	ft_free_redirect(t_command *cmd, int todel)
{
	free(cmd->args[todel]);
	free(cmd->args[todel + 1]);
	while (todel + 2 < cmd->nbarg)
	{
		cmd->args[todel] = cmd->args[todel + 2];
		todel++;
	}
	cmd->args[todel] = NULL;
	cmd->args[todel + 1] = NULL;
	cmd->nbarg -= 2;
}
