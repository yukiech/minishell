/* ************************************************************************** */
/*                                                                            */
/*                                        __                        __        */
/*                                    ___( o)>      CoinCoin ?    <(o )___    */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/21 17:44:53 by ahuber           ###   ########.fr       */
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
	int		oldi;

	oldi = 0;
	i = -1;
	res = ft_strdup("");
	while (++i < (int)ft_strlen(*arg))
	{
		if ((*arg)[i] == '$')
		{
			ft_soft_concat(&res, ft_substr(*arg, oldi, i - oldi));
			i++;
			oldi = i;
			while (ft_strchr(" \t\n\v\f\r$", (*arg)[i]) == NULL
				&& i < (int)ft_strlen(*arg))
				i++;
			ft_soft_concat(&res, ft_get_var(ft_substr(*arg, oldi, i - oldi), envp));
			oldi = i;
			if ((*arg)[i] == '$')
				i--;
		}
	}
	if (i > oldi)
		ft_soft_concat(&res, ft_substr(*arg, oldi, i));
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