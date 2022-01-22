/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:40:28 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/22 15:40:43 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit(t_command *cmds, t_builtin *bt)
{
	ft_free_builtins(bt);
	ft_free_commands(cmds, 1);
	ft_putendl_fd("exit", 1);
	exit(0);
}
