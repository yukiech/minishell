#ifndef MINISHELL_H
# define MINISHELL_H

//Read, write
# include <unistd.h>
//INT_MAX, INT_MIN
# include <stddef.h>
//Malloc, free
# include <stdlib.h>
//Va arg
# include <stdarg.h>
//Printf, scanf
# include <stdio.h>
//Signals
# include <signal.h>

// # include <readline/readline.h>
// # include "~/.brew/opt/readline/include/readline/history.h"

# include <readline/readline.h>
# include <readline/history.h>

//Libft, gnl, ft_printf
# include <mylibft.h>


//Store "cd" -> "cd_function"
typedef struct s_builtin_cmd {
	char *name;
	void (*function)(char **, char **);
}	t_builtin_cmd;

//Store x functions and x
typedef struct s_builtin {
	int				nb;
	t_builtin_cmd	**cmds;
}	t_builtin;

typedef struct s_commands {
	int	nb;
	char **cmds;
}	t_commands;




//main.c
int	main(int argc, char **argv, char **envp);


//ft_concat_tab.c
int	ft_concat_tab(char ***ptr, char *new);


//process_line.c
void	ft_process_pipes(char *line, t_builtin *bt, char **envp);

//process_commands.c
void	ft_process_commands(t_commands *cmds, t_builtin *bt, char **env);


//functions.c
t_builtin		*builtin_tab();


//ft_split_arg.c
typedef struct t_spliter {
	int	start_i;
	int	inside;
	int	oldinside;
	int	quote;
}	t_spliter;

char	**ft_split_arg(const char *s);


//builtin_cd.c
void	builtin_cd(char **argv, char **envp);

#endif
