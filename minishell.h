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

//main.c
int	main(int argc, char **argv, char **envp);



//ft_split_arg.c
typedef struct t_spliter {
	int	inside;
	int	quote;
}	t_spliter;

char	**ft_split_arg(const char *s);

#endif
