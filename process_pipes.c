/* ************************************************************************** */
/*                                                                            */
/*                                        __                        __        */
/*                                    ___( o)>      CoinCoin ?    <(o )___    */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/20 16:51:54 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count_pipes(char **parts);

void	ft_process_pipes(char *line, t_builtin *bt, char **envp)
{
	t_command	*commands;
	char		**parts;
	int			cmd_i;
	int			i;

	parts = ft_split_arg(line);
	commands = ft_calloc(ft_count_pipes(parts) + 1, sizeof(t_command));
	i = 0;
	cmd_i = 0;
	while (parts[i] != NULL)
	{
		if (ft_strncmp(parts[i], "|", 2) == 0)
		{
			free(parts[i]);
			cmd_i++;
		}
		else
			commands[cmd_i].nbarg = ft_concat_tab(&commands[cmd_i].args,
					parts[i]);
		i++;
	}
	free(parts);
	ft_process_commands(commands, bt, envp, cmd_i + 1);
}

void	ft_free_commands(t_command *cmds, int nbcmd)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbcmd)
	{
		j = 0;
		while (j < cmds[i].nbarg)
		{
			free(cmds[i].args[j]);
			j++;
		}
		free(cmds[i].args);
		i++;
	}
	free(cmds);
}

static int	ft_count_pipes(char **parts)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (parts[i] != NULL)
	{
		if (ft_strncmp(parts[i], "|", 1) == 0)
			count++;
		i++;
	}
	return (count);
}
