#include "minishell.h"

static int ft_count_pipes(char **parts);

void	ft_process_pipes(char *line, t_builtin *bt, char **envp)
{
	t_command	*commands;
	char **parts;
	int	cmd_i;
	int	i;

	parts = ft_split_arg(line);
	commands = ft_calloc(ft_count_pipes(parts) + 1, sizeof(t_command));
	i = 0;
	cmd_i = 0;
	while (parts[i] != NULL)
	{
		if (ft_strncmp(parts[i], "|", 2) == 0)
			cmd_i++;
		else
			commands[cmd_i].nbarg = ft_concat_tab(&commands[cmd_i].args, parts[i]);
		i++;
	}
	ft_process_commands(commands, bt, envp, cmd_i + 1);
}

static int ft_count_pipes(char **parts)
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

