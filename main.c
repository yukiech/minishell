/* ************************************************************************** */
/**/
/**/
/*   */
/**/
/*   By: */
/**/
/*   Created: 0000/00/00 00:00:00 by */
/*   Updated: 2022/01/22 11:05:39 by jjaqueme         ###   ########.fr       */
/**/
/* ************************************************************************** */

#include "minishell.h"
#include "evaluate_lst.c"
#include "env_lst.c"


void	display(t_evallst *lst, int l);

void	split(t_evallst **all, char *ptr, int *i, int *pre)
{
	while (*i < (int)ft_strlen(ptr) && ptr[*i] != ')')
	{
		printf("%c\n", ptr[*i]);	
		if (ptr[*i] == '"')
		{
			(*i)++;
			while (ptr[*i] != '"')
				(*i)++;			
		}
		else if (ptr[*i] == '\'' && *i < (int)ft_strlen(ptr))
		{
//			printf("rinfrionaaf   %d\n", *i);
			(*i)++;
			while (ptr[*i] != '\'' && *i < (int)ft_strlen(ptr))
				(*i)++;			
//			printf("rinfrionaaf   %d\n", *i);
		}

		else if (ft_strncmp(&ptr[*i], "&&", 2) == 0)
		{
			char *txt;

			printf("here1\n");
			if (*i - *pre > 0)
			{
				txt = ft_substr(ptr, *pre, *i - *pre);
//				printf("sub = %s\n", txt);
				eval_lstadd_back(all, eval_lstnew(txt, NULL));
			}
			eval_lstadd_back(all, eval_lstnew(NULL, ft_strdup("&&")));

			(*pre) += 2;
		}
		else if (ft_strncmp(&ptr[*i], "||", 2) == 0)
		{
			char *txt;

			printf("here2\n");
			if (*i - *pre > 0)
			{
				txt = ft_substr(ptr, *pre, *i - *pre);
//				printf("sub = %s\n", txt);
				eval_lstadd_back(all, eval_lstnew(txt, NULL));
			}
			eval_lstadd_back(all, eval_lstnew(NULL, ft_strdup("||")));

			(*pre) += 2;
		}

//		printf("%c\n", ptr[*i]);

		else if (ptr[*i] == '(')
		{
			char	*txt;
			txt = ft_substr(ptr, *pre, *i - *pre);
			eval_lstadd_back(all, eval_lstnew(txt, NULL));


			t_evallst *incep;

			incep = NULL;
			(*i)++;
			*pre = *i;

			printf("enter\n");
			split(&incep, ptr, i, pre);

			display(incep, 0);
			printf("adad\n");

			if (incep != NULL)
				eval_lstadd_child(all, incep);
		}
		if (*i < (int)ft_strlen(ptr))
			(*i)++;
	}


	printf("%d %d\n", *i, *pre);
	char	*txt;
	txt = ft_substr(ptr, *pre, *i - *pre);
	eval_lstadd_back(all, eval_lstnew(txt, NULL));
	*pre = *i + 1;
}



void	display(t_evallst *lst, int l)
{
	while (lst != NULL)
	{
		if (lst->op != NULL)	
			printf("%d, _%s_\n", l, lst->op);
		else
			display(lst->child, l + 1);
		lst = lst->next;
	}
}

void	ft_concat(char **base, char *append)
{
	char	*temp;

	if (append != NULL)
	{
		if (*base != NULL)
			{
			temp = ft_strjoin(*base, append);
			free(*base);
			free(append);
			*base = temp;
		}
		else
		{
			*base = append;
		}
	}
}


void	search_var(char **newtxt, int *i)
{
	int pre = *i;

}


void	take_variable(char **var)
{
	char *newtxt;

	int		i;
	int		pre;

	pre = 0;
	i = 0;
	while (i < (int)ft_strlen(*var))
	{
		if (ptr[*i] == '"')
		{
			(*i)++;
			while (ptr[*i] != '"' && *i < (int)ft_strlen(ptr))
				(*i)++;			
		}
		else if (ptr[*i] == '\'')
		{
			(*i)++;
			while (ptr[*i] != '\'' && *i < (int)ft_strlen(ptr))
				(*i)++;			
		}
		else if (ptr[*i] == '$')
		{
			ft_concat(&newtxt, ft_substr(ptr, pre, i - pre))
			search_var(&newtxt, &i);
		}


		i++;
	}

	(void)newtxt;
	(void)var;
	
}


void	interpret(t_evallst *lst)
{
	while (lst != NULL)
	{
		if (lst->op != NULL)
			printf(" _%s_\n", lst->op);
		else
			interpret(lst->child);
		lst = lst->next;
	}
}



int	main(int argc, char **argv, char **env)
{
    
	char	*ptr;

	t_evallst	*all;

	all = NULL;

	
	t_envlst *newenv = env_import(env);
	(void)newenv;
	env_print(newenv);


    if (argc == 3 && ft_strcmp(argv[1], "-c") == 0)
    {
		ptr = argv[2];
		printf("%s\n", ptr);

		int	i = 0;
		int	pre = 0;
		(void)i;
		(void)pre;


		split(&all, ptr, &i, &pre);

		if (ptr[i] != '\0')
			exit(printf("Error split\n"));

		
		display(all, 0);

    }
	else
	{
		char *tmp[2] = {"-a", NULL};

		int pid;

		pid = fork();
		if (pid == 0)
		{
			execve("/bin/ls", tmp, env);
			perror("Execve");
			exit(1);
		}
		waitpid(pid, NULL, 0);
	}
}




/*
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
*/
