CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
INCDIR = includes
SRC_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJDIR = $(SRCDIR)
TARGET = libft.a

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(TARGET): $(addprefix $(OBJDIR)/, $(OBJ_FILES))
	ar rc $(TARGET) $(addprefix $(OBJDIR)/, $(OBJ_FILES))
	ranlib $(TARGET)

all: $(TARGET)

clean:
	rm -f $(addprefix $(OBJDIR)/, $(OBJ_FILES))

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

.DEFAULT_GOAL := all

