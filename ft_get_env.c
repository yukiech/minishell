/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:42:08 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/22 15:42:09 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_env_too_long(int *i, int *i3, char **var_value)
{
	*i = 0;
	*i3 = 0;
	*var_value = NULL;
}

char	*ft_get_env(char **envp, char *asked_var)
{
	int		i;
	size_t	i2;
	int		i3;
	char	*var_value;

	ft_get_env_too_long(&i, &i3, &var_value);
	if (ft_strncmp(asked_var, "?=", 2) == 0)
		return (ft_itoa(g_exit_stat));
	while (envp[i])
	{
		if (ft_strncmp(envp[i], asked_var, ft_strlen(asked_var)) == 0)
		{
			var_value = malloc(sizeof(char) * ft_strlen(envp[i] + 1));
			i2 = ft_strlen(asked_var);
			while (i2 <= ft_strlen(envp[i]))
			{
				var_value[i3] = envp[i][i2];
				i3++;
				i2++;
			}
		}
		i++;
	}
	return (var_value);
}
