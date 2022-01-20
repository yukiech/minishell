/* ************************************************************************** */
/*                                                                            */
/*                                        __                        __        */
/*   builtin_default.c                                  :+:      :+:    :+:   */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/20 18:30:23 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_unite_path(char **base, char *path);
static int	test_and_exec_cmd(char **path_splitted, t_command cmd, char **envp);
static void	free_default(char **path_splitted);

void	builtin_default(t_command cmd, char **envp)
{
	char	*path;
	char	**path_splitted;
	char	pwd[PATH_MAX];
	char	*add_cmd;
	int		i;

	i = 0;
	path = getenv("PATH");
	path_splitted = ft_split(path, ':');
	add_cmd = ft_strjoin("/", cmd.args[0]);
	while (path_splitted[i] != NULL)
	{
		ft_unite_path(&path_splitted[i], add_cmd);
		i++;
	}
	if (ft_strlen(cmd.args[0]) > 0 && cmd.args[0][0] == '/')
		ft_concat_tab(&path_splitted, cmd.args[0]);
	else
	{
		getcwd(pwd, PATH_MAX);
		ft_concat_tab(&path_splitted, ft_strdup(pwd));
		ft_unite_path(&path_splitted[i], add_cmd);
	}
	free(add_cmd);
	test_and_exec_cmd(path_splitted, cmd, envp);
	free_default(path_splitted);
}

static void	ft_unite_path(char **base, char *path)
{
	char	*temp;

	temp = ft_strjoin(*base, path);
	free(*base);
	*base = temp;
}

static int	test_and_exec_cmd(char **path_splitted, t_command cmd, char **envp)
{
	int	i;

	i = 0;
	while (path_splitted[i])
	{
		if ((access(path_splitted[i], F_OK)) == 0)
		{
			execve(path_splitted[i], cmd.args, envp);
			return (0);
		}
		else
			i++;
	}
	return (1);
}

static void	free_default(char **path_splitted)
{
	int	i;

	i = 0;
	while (path_splitted[i])
	{
		free(path_splitted[i]);
		i++;
	}
	free(path_splitted);
}
