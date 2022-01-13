/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:51 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/18 18:17:14 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_split_init(int *i, int *start_i, int *oldinside, t_spliter *sp);
static void	ft_make_splits(const char *s, char ***ptr);
static void	ft_decide_split(char c, t_spliter *sp);
static void	ft_cut_add(const char *s, int i, int start_i, char ***ptr);

char	**ft_split_arg(const char *s)
{
	char	**ptr;

	if (s == NULL)
		return (NULL);
	ptr = malloc(sizeof(char *) * 1);
	ptr[0] = NULL;
	ft_make_splits(s, &ptr);
	return (ptr);
}

static void	ft_split_init(int *i, int *start_i, int *oldinside, t_spliter *sp)
{
	*i = 0;
	*start_i = 0;
	*oldinside = 0;
	sp->inside = 0;
	sp->quote = 0;
}

static void	ft_make_splits(const char *s, char ***ptr)
{
	int			i;
	int			start_i;
	int			oldinside;
	t_spliter	sp;

	ft_split_init(&i, &start_i, &oldinside, &sp);
	while (s[i] != '\0')
	{
		ft_decide_split(s[i], &sp);
		if (oldinside != sp.inside)
		{
			if (sp.inside == 1)
				start_i = i;
			else
			{
				ft_cut_add(s, i, start_i, ptr);
				start_i = -1;
			}
			oldinside = sp.inside;
		}
		i++;
	}
	if (start_i != -1)
		ft_cut_add(s, i, start_i, ptr);
}

static void	ft_decide_split(char c, t_spliter *sp)
{
	if (c == '\'')
	{
		if (sp->quote == 0)
			sp->quote = 1;
		else if (sp->quote == 1)
			sp->quote = 0;
		sp->inside = 1;
	}
	else if (c == '"')
	{
		if (sp->quote == 0)
			sp->quote = 2;
		else if (sp->quote == 2)
			sp->quote = 0;
		sp->inside = 1;
	}
	else if (sp->inside == 0 && c != ' ' && sp->quote == 0)
		sp->inside = 1;
	else if (sp->inside == 1 && c == ' ' && sp->quote == 0)
		sp->inside = 0;
}

static void	ft_cut_add(const char *s, int i, int start_i, char ***ptr)
{
	int		count;
	char	**newptr;

	count = 0;
	while ((*ptr)[count] != NULL)
		count++;
	newptr = malloc(sizeof(char *) * (count + 2));
	newptr[count + 1] = NULL;
	newptr[count] = ft_substr(s, start_i, i - start_i);
	while (count > 0)
	{
		count--;
		newptr[count] = (*ptr)[count];
	}
	free(*ptr);
	*ptr = newptr;
}

