/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:40:02 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/22 15:40:06 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(t_command cmd, char **envp)
{
	int	newline;
	int	i;

	(void)envp;
	newline = 0;
	i = 1;
	g_exit_stat = 0;
	if (i < cmd.nbarg && ft_strncmp(cmd.args[i], "-n", 2) == 0)
	{
		newline = 1;
		i++;
	}
	while (i < cmd.nbarg)
	{
		ft_putstr_fd(cmd.args[i], 1);
		if (i < cmd.nbarg - 1)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (newline == 0)
		ft_putstr_fd("\n", 1);
	newline = 0;
}
