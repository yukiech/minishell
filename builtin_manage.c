#include "minishell.h"

static t_builtin_cmd *new_builtin(char *name, void (*f)(t_command, char **));

t_builtin *builtin_tab()
{
	t_builtin	*tab;

	tab = malloc(sizeof(t_builtin));
	tab->nb = 6;

	tab->cmds = malloc(sizeof(t_builtin_cmd *) * tab->nb);

	tab->cmds[0] = new_builtin("cd", &builtin_cd);
	tab->cmds[1] = new_builtin("pwd", &builtin_pwd);
	tab->cmds[2] = new_builtin("env", &builtin_env);
	tab->cmds[3] = new_builtin("echo", &builtin_echo);
	tab->cmds[4] = new_builtin("export", &builtin_export);
	tab->cmds[5] = new_builtin("unset", &builtin_unset);

	return (tab);
}

void	ft_free_builtins(t_builtin *tab)
{
	int	i;

	i = 0;
	while (i < tab->nb)
	{
		free(tab->cmds[i]);
		i++;
	}
	free(tab->cmds);
	free(tab);
}

static t_builtin_cmd *new_builtin(char *name, void (*f)(t_command, char **))
{
	t_builtin_cmd	*new;

	new = malloc(sizeof(t_builtin_cmd));
	new->name = name;
	new->function = f;
	return (new);
}
