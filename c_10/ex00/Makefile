CC = cc
CFLAGS = -Wall -Werror

all: ft_display_file

ft_display_file: ft_display_file.c
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -f ft_display_file

fclean: clean

re: fclean all

.PHONY: all clean fclean re
