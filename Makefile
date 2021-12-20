SRCS_DIR	= ./
SRCS_FILES	= main.c
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

CFLAGS		= -Wall -Wextra -Werror

HEADS		= -I. -I${LIBFT} -I${HOME}/.brew/Cellar/readline/8.1.1/include/

LIBS		= -L${HOME}/.brew/Cellar/readline/8.1.1/lib/ -lreadline -lhistory

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${HEADS} 

all:		${NAME}

${NAME}:	${OBJS}
			${MAKELIB} all
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}/libft.a ${LIBS}

${NAMEB}:	${OBJSB}
			${MAKELIB} all
			${CC} ${CFLAGS} -o ${NAMEB} ${OBJSB} ${LIBFT}/libft.a ${LIBS}

bonus:		${NAMEB}

clean:
			${RM} ${OBJS} ${OBJSB}
			${MAKELIB} clean

fclean:		clean
			${RM} ${NAME} ${NAMEB}
			${MAKELIB} fclean

re:			fclean all

.PHONY:		all bonus clean fclean re
