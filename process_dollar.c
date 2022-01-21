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
