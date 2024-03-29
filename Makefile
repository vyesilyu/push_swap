NAME = push_swap
SRCS = cost_a.c cost_b.c do_cost_a.c do_cost_b.c \
		error.c init.c sort.c push_swap.c \
		utils.c stack_utils.c swap.c push.c \
		rotate.c reverse_rotate.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean:
	@${MAKE} -C ./libft fclean
	@${RM} *.o

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re