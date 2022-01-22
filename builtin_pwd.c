/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:41:20 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/22 15:41:22 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(t_command cmd, char **envp)
{
	char	pwd[PATH_MAX];

	(void)cmd;
	(void)envp;
	g_exit_stat = 0;
	if (getcwd(pwd, PATH_MAX))
	{
		ft_putendl_fd(pwd, 1);
	}
}
