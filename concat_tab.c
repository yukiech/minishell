/* ************************************************************************** */
/*                                                                            */
/*                                        __                        __        */
/*                                    ___( o)>      CoinCoin ?    <(o )___    */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/20 17:21:53 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_concat_tab(char ***ptr, char *new)
{
	char	**newptr;
	int		count;
	int		i;

	count = 0;
	while ((*ptr) != NULL && (*ptr)[count] != NULL)
		count++;
	newptr = ft_calloc(count + 2, sizeof(char *));
	newptr[count + 1] = NULL;
	newptr[count] = new;
	i = 0;
	while (i < count)
	{
		newptr[i] = (*ptr)[i];
		i++;
	}
	if (*ptr != NULL)
		free(*ptr);
	*ptr = newptr;
	return (count + 1);
}
