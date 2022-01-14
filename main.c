
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_builtin	*builtins;

	builtins = builtin_tab();

	printf("[DEBUG] text: %d, %d, %s, %s\n", (int)ft_strlen("text"), argc, argv[0], envp[0]);


	line = malloc(0);
	while (line != NULL)
	{
		free(line);
		line = readline("Test : ");

		if (line == NULL || ft_strlen(line) == 0)
			continue ;

		add_history(line);
		printf("[DEBUG] line : %s\n", line);

		ft_process_pipes(line, builtins, envp);

		rl_replace_line("", 0);
	}
}
