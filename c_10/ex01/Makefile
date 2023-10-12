CC = cc
CFLAGS = -Wall -Werror

all: ft_cat

ft_cat: ft_cat.c
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -f ft_cat

fclean: clean

re: fclean all

.PHONY: all clean fclean re
