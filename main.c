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
	proc = 1;
	if (signo == SIGINT && proc == 0)
	{
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

void	ft_shell(t_builtin *builtins, char **envp)
{
	char	*line;
	int		end;

	end = 0;
	while (end == 0)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_signal(0, 0);
		line = readline("CoinCoinShell-4.2$ ");
		ft_signal(0, 1);
		if (line != NULL && ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		if (line == NULL)
		{
			end = 1;
			continue ;
		}
		add_history(line);
		ft_process_pipes(line, builtins, envp);
	}	
}

int	main(int argc, char **argv, char **envp)
{
	t_builtin		*builtins;
	struct termios	saved;

	(void)argc;
	(void)argv;
	builtins = builtin_tab();
	ft_set_termios(&saved);
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, ft_sig_handler);
	ft_shell(builtins, envp);
	ft_free_builtins(builtins);
	tcsetattr(STDIN_FILENO, TCSANOW, &saved);
}
