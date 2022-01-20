/* ************************************************************************** */
/*                                                                            */
/*   CoinCoinShell.c                      __                        __        */
/*                                    ___( o)>      CoinCoin ?    <(o )___    */
/*                                   \\ <_. )       CoinCoin !     ( ._> /    */
/*   By: CoinCoinTheRetour             `---'                        `---'     */
/*                                                                            */
/*   Created: 2012/12/21 12:34:56 by CoinCoinTheRetour                        */
/*   Updated: 2022/01/20 16:35:22 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_ascii(void)
{
	char	*art;

	art = "############################################################\n";
	write(1, art, 62);
	art = "#         __                                     __        #\n";
	write(1, art, 62);
	art = "#     ___( o)>     Minishell by Coin-Coin      <(o )___    #\n";
	write(1, art, 62);
	art = "#     \\ <_. )    coded by Jjaqueme & Ahuber     ( ._> /    #\n";
	write(1, art, 62);
	art = "#      `---'                                     `---'     #\n";
	write(1, art, 62);
	art = "#                                                          #\n";
	write(1, art, 62);
	art = "############################################################\n";
	write(1, art, 62);
}
