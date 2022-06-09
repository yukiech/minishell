/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:43:52 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/22 15:45:43 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_process_commands(t_command *cmds,
			t_builtin *bt, char **envp, int nbcmd)
{
	int	i;

	ft_process_redirect(cmds, nbcmd);
	if (cmds[0].fdin == -1)
		cmds[0].fdin = 0;
	if (cmds[nbcmd - 1].fdout == -1)
		cmds[nbcmd - 1].fdout = 1;
	process_quote(cmds, nbcmd);
	process_dollar(cmds, envp, nbcmd);
	ft_process_fds(cmds, nbcmd);
	ft_launch_commands(cmds, bt, envp, nbcmd);
	i = 0;
	while (i < nbcmd)
	{
		if (cmds[i].fdin != 0)
			close(cmds[i].fdin);
		if (cmds[i].fdout != 1)
			close(cmds[i].fdout);
		i++;
	}
	ft_free_commands(cmds, nbcmd);
}
