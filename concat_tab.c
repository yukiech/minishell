/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:41:59 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/22 15:42:00 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_concat_tab(char ***ptr, char *new)
{
	char	**newptr;
	int		count;
	int		i;

	count = 0;
	while ((*ptr) != NULL && (*ptr)[count] != NULL)
		count++;
	newptr = ft_calloc(count + 2, sizeof(char *));
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
