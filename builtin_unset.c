/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:41:36 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/22 15:41:38 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_unset(t_command cmd, char **envp)
{
	int		i;
	char	*var_temp;

	i = 0;
	var_temp = cmd.args[1];
	g_exit_stat = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var_temp, ft_strlen(var_temp)) == 0)
		{
			if (envp[i][ft_strlen(var_temp)] == '=')
			{
				while (envp[i + 1])
				{
					envp[i] = envp[i + 1];
					i++;
				}
				envp[i] = NULL;
			}
		}
		i++;
	}
}
