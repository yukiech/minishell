#include "minishell.h"

static t_builtin_cmd *new_builtin(char *name, void (*f)(char **, char **));

t_builtin *builtin_tab()
{
	t_builtin	*tab;

	tab = malloc(sizeof(t_builtin));
	tab->nb = 1;

	tab->cmds = malloc(sizeof(t_builtin_cmd *) * tab->nb);

	tab->cmds[0] = new_builtin("cd", &builtin_cd);

	return (tab);
}

static t_builtin_cmd *new_builtin(char *name, void (*f)(char **, char **))
{
	t_builtin_cmd	*new;

	new = malloc(sizeof(t_builtin_cmd));
	new->name = name;
	new->function = f;
	return (new);
}
