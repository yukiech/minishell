#include "minishell.h"

int	ft_concat_tab(char ***ptr, char *new)
{
	int		count;
	char	**newptr;

	count = 0;
	while ((*ptr) != NULL && (*ptr)[count] != NULL)
		count++;

	newptr = malloc(sizeof(char *) * (count + 2));
	newptr[count + 1] = NULL;
	newptr[count] = new;

	while (count > 0)
	{
		count--;
		newptr[count] = (*ptr)[count];
	}
	if (*ptr != NULL)
		free(*ptr);
	*ptr = newptr;
	return (count + 1);
}