/* ************************************************************************** */
/*                                                                            */
/*   CoinCoinShell.c                      __                        __        */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/21 21:34:00 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_oldpwd(char **envp)
{
	int	i;
	char *temp;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
		{
			temp = ft_get_env(envp, "PWD=");
			temp = ft_strjoin("OLDPWD=", temp);
			printf("replace by: %s\n", temp);
			envp[i] = temp;
		}
		i++;
	}
}

void	update_pwd(char **envp)
{
	int	i;
	char *temp;
	char	pwd[PATH_MAX];

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
		{
			getcwd(pwd, PATH_MAX);
			temp = ft_strjoin("PWD=", pwd);
			printf("replace by: %s\n", temp);
			envp[i] = temp;
		}
		i++;
	}
}

void	builtin_cd(t_command cmd, char **envp)
{
	int		i;
	char	*temp;

	i = 1;
	if (cmd.nbarg >= 2)
	{
		if(chdir(cmd.args[i]) == -1)
			perror("CoinCoinShell: cd");
	}
	else
	{
		update_oldpwd(envp);
		temp = ft_get_env(envp, "HOME=");
		if (temp != NULL)
		{
			if (chdir(temp) == -1)
				perror("CoinCoinShell: cd");
			if (temp != NULL)
				free(temp);
		}
		else
			coin_error2("cd", "HOME not set");
		update_pwd(envp);
	}
}
