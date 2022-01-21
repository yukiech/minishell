/* ************************************************************************** */
/**/
/**/
/*   */
/**/
/*   By: */
/**/
/*   Created: 0000/00/00 00:00:00 by */
/*   Updated: 0000/00/00 00:00:00 by */
/**/
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal(int signo, int run)
{
	static int	proc = 0;
	static int	running = 0;

	if (run == 1)
		running = 1;
	else if (run == 0)
		running = 0;
	if (run != -1)
		return ;
	if (signo == SIGINT && proc == 0)
	{
		proc = 1;
		rl_replace_line("", 0);
		ft_putendl_fd("", 1);
		if (running == 0)
			rl_on_new_line();
		if (running == 0)
			rl_redisplay();
		running = 0;
	}
	if (signo == SIGQUIT && proc == 0 && running == 0)
		rl_on_new_line();
	if (signo == SIGQUIT && proc == 0 && running == 0)
		rl_redisplay();
	proc = 0;
}

void	ft_sig_handler(int signo)
{
	ft_signal(signo, -1);
}

void	ft_set_termios(struct termios *saved)
{
	struct termios	attr;

	tcgetattr(STDIN_FILENO, saved);
	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);
}
