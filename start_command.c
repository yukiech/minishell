#include "minishell.h"

void	ft_start_command(t_command cmd, t_builtin *bt, char **envp)
{
	int	i;

	i = 0;
	while (i < bt->nb)
	{
		if (ft_strncmp(cmd.args[0], bt->cmds[i]->name, ft_strlen(bt->cmds[i]->name + 1)) == 0)
		{
			bt->cmds[i]->function(cmd, envp);
			break ;
		}
		i++;
	}
	if (i == bt->nb)
		builtin_default(cmd, envp);
}
