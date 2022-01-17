#include "minishell.h"

int	ft_concat_tab(char ***ptr, char *new)
{
	char	**newptr;
	int		count;
	int		i;

	count = 0;
	while ((*ptr) != NULL && (*ptr)[count] != NULL)
		count++;

	newptr = malloc(sizeof(char *) * (count + 2));
	newptr[count + 1] = NULL;
	newptr[count] = new;

	i = 0;
	while (i < count)
	{
		newptr[i] = (*ptr)[i];
		i++;
	}
	if (*ptr != NULL)
		free(*ptr);
	*ptr = newptr;
	return (count + 1);
}