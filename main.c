/* ************************************************************************** */
/**/
/**/
/*   */
/**/
/*   By: */
/**/
/*   Created: 0000/00/00 00:00:00 by */
/*   Updated: 2022/01/22 11:05:39 by ahuber           ###   ########.fr       */
/**/
/* ************************************************************************** */

#include "minishell.h"

static void	ft_set_termios(struct termios *saved);
static void	ft_shell(t_builtin *builtins, char **envp);

int	g_exit_stat = 0;

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

static void	ft_shell(t_builtin *builtins, char **envp)
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

static void	ft_set_termios(struct termios *saved)
{
	struct termios	attr;

	tcgetattr(STDIN_FILENO, saved);
	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attr);
}
