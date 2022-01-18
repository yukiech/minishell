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
//PATH_MAX
# include <limits.h>


// # include <readline/readline.h>
// # include "~/.brew/opt/readline/include/readline/history.h"

# include <readline/readline.h>
# include <readline/history.h>

//Libft, gnl, ft_printf
# include <mylibft.h>


# define FILE_PERM S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

typedef struct s_command {
	int	nbarg;
	int	fdin;
	int	fdout;
	char **args;
}	t_command;


//Store "cd" -> "cd_function"
typedef struct s_builtin_cmd {
	char *name;
	void (*function)(t_command, char **);
}	t_builtin_cmd;

//Store x functions and x
typedef struct s_builtin {
	int				nb;
	t_builtin_cmd	**cmds;
}	t_builtin;




//main.c
int	main(int argc, char **argv, char **envp);


//ft_concat_tab.c
int	ft_concat_tab(char ***ptr, char *new);


//process_pipes.c
void   ft_process_pipes(char *line, t_builtin *bt, char **envp);
void   ft_free_commands(t_command *cmds, int nbcmd);

//process_commands.c
void	ft_process_commands(t_command *cmds, t_builtin *bt, char **env, int nbcmd);

//process_redirect.c
void	ft_process_redirect(t_command *cmds, int nbcmd);

//functions.c
t_builtin		*builtin_tab();
void			ft_free_builtins(t_builtin *tab);


//ft_split_arg.c
typedef struct t_spliter {
	int	start_i;
	int	inside;
	int	oldinside;
	int	quote;
}	t_spliter;

char	**ft_split_arg(const char *s);


//builtin_default.c
void	builtin_default(t_command cmd, char **envp);

//builtin_cd.c
void	builtin_cd(t_command cmd, char **envp);

//builtin_pwd.c
void	builtin_pwd(t_command cmd, char **envp);

//builtin_env.c
void	builtin_env(t_command cmd, char **envp);

#endif
