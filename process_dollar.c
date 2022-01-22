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

static void	ft_parse_vars(char **arg, char **envp)
{
	char	*res;
	int		i;
	int		oldi;

	oldi = 0;
	i = -1;
	res = ft_strdup("");
	while (++i < (int)ft_strlen(*arg))
	{
		if ((*arg)[i] == '$')
		{
			ft_soft_concat(&res, ft_substr(*arg, oldi, i));
			i++;
			oldi = i;
			while (!ft_isspace((*arg)[i]) && i < (int)ft_strlen(*arg)
				&& (*arg)[i] != '$')
				i++;
			ft_soft_concat(&res, ft_get_var(ft_substr(*arg, oldi, i), envp));
			oldi = i;
		}
	}
	if (i > oldi)
		ft_soft_concat(&res, ft_substr(*arg, oldi, i));
	free(*arg);
	*arg = res;
}

static void	ft_process_arg(char **arg, char **envp)
{
	char	*res;

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
	ft_parse_vars(arg, envp);
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

/*
void	process_dollar(t_command *cmds, char **envp, int nbcmd)
{
	int		i;
	int		i2;
	int		i3;
	char	*asked_var;

	i = 0;
	i2 = 1;
	i3 = 0;
	while (i < nbcmd)
	{
		i2 = 1;
		i3 = 0;
		while (i2 < cmds[i].nbarg)
		{
			if (cmds[i].args[i2][i3] == '$')
			{
				asked_var = cmds[i].args[i2];
				while (asked_var[i3 + 1])
				{
					asked_var[i3] = asked_var[i3 + 1];
					i3++;
				}
				asked_var[i3] = '=';
				cmds[i].args[i2] = ft_get_env(envp, asked_var);
				free(asked_var);
			}
			i2++;
		}
		i++;
	}
}
*/
