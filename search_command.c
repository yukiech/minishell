/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:45:00 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/22 15:45:03 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_single_fork(t_command *cmds, t_builtin *bt, char **envp)
{
	int	status;
	int	pid;

	pid = fork();
	if (pid == 0)
	{	
		status = builtin_default(cmds[0], envp);
		ft_free_builtins(bt);
		ft_free_commands(cmds, 1);
		exit(status);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exit_stat = WEXITSTATUS(status);
}

void	ft_search_command(t_command *cmds,
			t_builtin *bt, char **envp, int forked)
{
	int	i;

	i = -1;
	while (++i < bt->nb)
	{
		if (ft_strcmp(cmds[0].args[0], bt->cmds[i]->name) == 0)
			bt->cmds[i]->function(cmds[0], envp);
		if (ft_strcmp(cmds[0].args[0], bt->cmds[i]->name) == 0)
			break ;
	}
	if (i == bt->nb && ft_strcmp(cmds[0].args[0], "exit") == 0)
	{
		builtin_exit(cmds, bt);
		i++;
	}	
	if (i == bt->nb && forked == 0)
		ft_single_fork(cmds, bt, envp);
	else if (i == bt->nb)
		builtin_default(cmds[0], envp);
}
