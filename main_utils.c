/* ************************************************************************** */
/**/
/**/
/*   */
/**/
/*   By: */
/**/
/*   Created: 0000/00/00 00:00:00 by */
/*   Updated: 2022/01/22 11:47:15 by ahuber           ###   ########.fr       */
/**/
/* ************************************************************************** */

#include "minishell.h"

static void	ft_sig_sigint(int signo, int *proc, int *running)
{
	if (*proc == 0)
	{
		*proc = 1;
		rl_replace_line("", 0);
		ft_putendl_fd("", 1);
		if (*running == 0)
		{	
			rl_on_new_line();
			rl_redisplay();
			g_exit_stat = 1;
		}
		else
		{
			g_exit_stat = 128 + signo;
		}
		*running = 0;
	}
	*proc = 0;
}

static void	ft_sig_sigquit(int signo, int *proc, int *running)
{
	if (*proc == 0)
	{
		*proc = 1;
		rl_on_new_line();
		rl_redisplay();
		if (*running == 1)
		{	
			g_exit_stat = 128 + signo;
		}
		*running = 0;
	}
	*proc = 0;
}

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
	if (signo == SIGINT)
		ft_sig_sigint(signo, &proc, &running);
	if (signo == SIGQUIT)
		ft_sig_sigquit(signo, &proc, &running);
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
