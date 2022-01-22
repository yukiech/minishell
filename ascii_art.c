/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_art.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:34:08 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/22 15:34:14 by ahuber           ###   ########.fr       */
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
