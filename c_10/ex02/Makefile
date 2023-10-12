CC = cc
CFLAGS = -Wall -Werror

all: ft_tail

ft_tail: ft_tail.c ft_tail_2.c
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -f ft_tail

fclean: clean

re: fclean all

.PHONY: all clean fclean re
