
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char *line;

	printf("text: %d, %d, %s, %s\n", (int)ft_strlen("text"), argc, argv[0], envp[0]);

	line = malloc(0);
	while (line != NULL)
	{
		free(line);
		line = readline("Test : ");
		printf("line : %s\n", line);
		rl_replace_line("", 0);
	}
}
