CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = do-op
OBJS = ${SRCS:.c=.o}
SRCS = sources/ft_do_op.c sources/ft_do_op_2.c sources/ft_do_op_3.c

.c.o: 
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o