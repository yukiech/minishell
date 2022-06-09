/* ************************************************************************** */
/*                                                                            */
/*                                        __                        __        */
/*                                    ___( o)>      CoinCoin ?    <(o )___    */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/22 10:11:20 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_quote(t_command *cmds, int nbcmd)
{
	int	i;
	int	i2;
	int	i3;

	i = 0;
	while (i < nbcmd)
	{
		i2 = 1;
		i3 = 0;
		while (i2 < cmds[i].nbarg)
		{
			printf(" base %s\n" , cmds[i].args[i2]);
			if (cmds[i].args[i2][i3] == '\'')
			{
				while (cmds[i].args[i2][i3 + 1] != '\''
						&& cmds[i].args[i2][i3 + 1])
				{
					cmds[i].args[i2][i3] = cmds[i].args[i2][i3 + 1];
					i3++;
				}
				cmds[i].args[i2][i3] = '\0';
			}
			i2++;
		}
		i++;
	}
}
