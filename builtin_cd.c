/* ************************************************************************** */
/*                                                                            */
/*   CoinCoinShell.c                      __                        __        */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                    \ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/22 14:07:26 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_oldpwd(char **envp, char *oldpwd)
{
	int		i;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
		{
			temp = ft_strjoin("OLDPWD=", oldpwd);
			envp[i] = temp;
		}
		i++;
	}
}

static void	update_pwd(char **envp)
{
	int		i;
	char	*temp;
	char	pwd[PATH_MAX];

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
		{
			getcwd(pwd, PATH_MAX);
			temp = ft_strjoin("PWD=", pwd);
			envp[i] = temp;
		}
		i++;
	}
}

static void	update_both(char **envp, char *oldpwd)
{
	update_oldpwd(envp, oldpwd);
	update_pwd(envp);
}

static void	builtin_cd_is_too_long(char **envp, char *temp_pwd, char *temp)
{
	if (chdir(temp) == -1)
		coin_error_errno("cd");
	if (temp != NULL)
		free(temp);
	update_both(envp, temp_pwd);
}

void	builtin_cd(t_command cmd, char **envp)
{
	int		i;
	char	*temp;
	char	temp_pwd[PATH_MAX];

	i = 1;
	g_exit_stat = 0;
	getcwd(temp_pwd, PATH_MAX);
	if (cmd.nbarg >= 2)
	{
		if (chdir(cmd.args[i]) == -1)
			coin_error_errno("cd");
		else
		{
			update_both(envp, temp_pwd);
			g_exit_stat = 0;
		}
	}
	else
	{
		temp = ft_get_env(envp, "HOME=");
		if (temp != NULL)
			builtin_cd_is_too_long(envp, temp_pwd, temp);
		else
			coin_error2("cd", "HOME not set");
	}
}
