#include "minishell.h"

typedef struct s_evallst
{
	char				*op;
	struct s_evallst	*child;

	int					isbin;
	struct s_evallst	*next;
	struct s_evallst	*parent;
}	t_evallst;


t_evallst	*eval_lstnew(char *content, char *bin)
{
	t_evallst	*new_lst;

	new_lst = ft_calloc(1, sizeof(t_evallst));

	if (new_lst == NULL)
		return (NULL);

	new_lst->isbin = 0;
	new_lst->child = NULL;
	if (content != NULL)
		new_lst->op = content;

	if (bin != NULL)
	{
		new_lst->op = bin;
		new_lst->isbin = 1;
	}

	new_lst->next = NULL;
	return (new_lst);
}

int	eval_lstsize(t_evallst *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	eval_lstclear(t_evallst **lst)
{
	t_evallst	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		free((*lst)->op);
		free(*lst);
		*lst = next;
	}
}

void	eval_lstadd_back(t_evallst **alst, t_evallst *new)
{
	t_evallst	*lastlst;

	lastlst = *alst;
	while (lastlst != NULL && lastlst->next != NULL)
		lastlst = lastlst->next;

	if (lastlst != NULL)
		lastlst->next = new;
	else
		*alst = new;
}

void	eval_lstadd_child(t_evallst **alst, t_evallst *child)
{
	t_evallst	*lastlst;
	t_evallst	*new;

	lastlst = *alst;
	while (lastlst != NULL && lastlst->next != NULL)
		lastlst = lastlst->next;

	new = ft_calloc(1, sizeof(t_evallst));
	if (new == NULL)
		return ;
	new->op = NULL;
	new->child = child;
	
	if (lastlst != NULL)
		lastlst->next = new;
	else
		*alst = new;
}