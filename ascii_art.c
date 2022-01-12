#include "minishell.h"

void	start_ascii()
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
