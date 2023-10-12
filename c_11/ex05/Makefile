CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = do-op
OBJS = ${SRCS:.c=.o}
SRCS = sources/ft_do_op.c sources/ft_do_op_2.c sources/ft_do_op_3.c

all:
	@${CC} ${CFLAGS} ${SRCS} -o ${NAME}

do-op: all

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all
