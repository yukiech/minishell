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
	static int proc = 0;
	static int running = 0;

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
		{
			rl_on_new_line();
			rl_redisplay();
		}
		running = 0;
		proc = 0;
	}
	else if (signo == SIGQUIT && proc == 0)
	{
		proc = 1;
		rl_on_new_line();
		rl_redisplay();
		proc = 0;
	}
}

void	ft_sig_handler(int signo)
{
	ft_signal(signo, -1);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char		*line;
	t_builtin	*builtins;
//	sigset_t	set;
//	struct sigaction act;

	builtins = builtin_tab();
/*	sigfillset(&set);
	act.sa_flags = 0;
	act.sa_mask = set;
	act.sa_sigaction = &ft_signal;
	sigaction(SIGINT, &act, NULL);  //Ctrl-c
	sigaction(SIGQUIT, &act, NULL); //Ctrl-\
*/

	struct termios saved;
	struct termios attr;

    tcgetattr(STDIN_FILENO, &saved);
    tcgetattr(STDIN_FILENO, &attr);

	attr.c_lflag &= ~ECHOCTL;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);

	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, ft_sig_handler);


	line = malloc(0);
	while (line != NULL)
	{
//		printf("\n\n\n\n");
		free(line);
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_signal(0, 0);
		line = readline("CoinCoinShell-4.2$ ");
		ft_signal(0, 1);

		if (line == NULL || ft_strlen(line) == 0)
			continue ;

		add_history(line);
//		printf("[DEBUG] line : %s\n", line);

		ft_process_pipes(line, builtins, envp);

	}

	tcsetattr(STDIN_FILENO, TCSANOW, &saved);
}
