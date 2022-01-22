SRCS_DIR	= ./
SRCS_FILES	= main.c main_utils.c split_arg.c concat_tab.c ft_get_env.c coin_error.c ascii_art.c \
	process_pipes.c process_commands.c process_redirect.c process_fds.c process_dollar.c process_quote.c \
	launch_commands.c search_command.c \
	builtin_manage.c builtin_cd.c builtin_pwd.c builtin_env.c builtin_default.c builtin_echo.c builtin_export.c builtin_unset.c  builtin_exit.c

SRCS		= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

BONUS_DIR	= ./
BONUS_FILES	= 
BONUS		= ${patsubst %, ${BONUS_DIR}%, ${BONUS_FILES}}

LIBFT		= ./libft/
MAKELIB		= ${MAKE} -C ${LIBFT}

OBJS		= ${SRCS:.c=.o}
OBJSB		= ${BONUS:.c=.o}

NAME		= minishell
NAMEB		= minishell_bonus

CC			= gcc
AR			= ar rcs
CP			= cp -f
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

HEADS		= -I. -I${LIBFT} -I${HOME}/.brew/Cellar/readline/8.1.1/include/

LIBS		= -L${HOME}/.brew/Cellar/readline/8.1.1/lib/ -lreadline -lhistory

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${HEADS}

all:		${NAME}

${NAME}:	${OBJS}
			@tput setaf 46
			${MAKELIB} all
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}/libft.a ${LIBS}

${NAMEB}:	${OBJSB}
			${MAKELIB} all
			${CC} ${CFLAGS} -o ${NAMEB} ${OBJSB} ${LIBFT}/libft.a ${LIBS}

bonus:		${NAMEB}

clean:
			@tput setaf 1
			${RM} ${OBJS} ${OBJSB}
			${MAKELIB} clean
			@tput setaf 46

fclean:		clean
			@tput setaf 1
			${RM} ${NAME} ${NAMEB}
			${MAKELIB} fclean
			@tput setaf 46

re:			fclean all

.PHONY:		all bonus clean fclean re
