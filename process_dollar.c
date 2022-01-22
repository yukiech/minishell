/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:44:06 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/22 15:44:07 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_var(char *var_name, char **envp)
{
	char	*temp;
	char	*res;

	temp = ft_strjoin(var_name, "=");
	free(var_name);
	res = ft_get_env(envp, temp);
	free(temp);
	if (res != NULL)
		return (res);
	else
		return (ft_strdup(""));
}

static void	ft_soft_concat(char **base, char *new)
{
	char	*temp;

	if (new != NULL)
	{
		temp = ft_strjoin(*base, new);
		free(*base);
		free(new);
		*base = temp;
	}
}

static char	*ft_parse_vars(char **arg, char **envp)
{
	char	*res;
	int		i;
	int		oi;

	oi = 0;
	i = -1;
	res = ft_strdup("");
	while (++i < (int)ft_strlen(*arg))
	{
		if ((*arg)[i] == '$')
		{
			ft_soft_concat(&res, ft_substr(*arg, oi, i - oi));
			i++;
			oi = i;
			while (!ft_strchr(VAR_END, (*arg)[i]) && i < (int)ft_strlen(*arg))
				i++;
			ft_soft_concat(&res, ft_get_var(ft_substr(*arg, oi, i - oi), envp));
			oi = i;
			if ((*arg)[i] == '$')
				i--;
		}
	}
	if (i > oi)
		ft_soft_concat(&res, ft_substr(*arg, oi, i));
	return (res);
}

static void	ft_process_arg(char **arg, char **envp)
{
	char	*res;
	char	*temp;

	if (*arg[0] == '\'')
	{
		res = ft_substr(*arg, 1, ft_strlen(*arg) - 2);
		free(*arg);
		*arg = res;
		return ;
	}
	else if (*arg[0] == '"')
	{
		res = ft_substr(*arg, 1, ft_strlen(*arg) - 2);
		free(*arg);
		*arg = res;
	}
	temp = ft_parse_vars(arg, envp);
	free(*arg);
	*arg = temp;
}

void	process_dollar(t_command *cmds, char **envp, int nbcmd)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbcmd)
	{
		j = 0;
		while (j < cmds[i].nbarg)
		{
			ft_process_arg(&cmds[i].args[j], envp);
			j++;
		}
		i++;
	}
}
