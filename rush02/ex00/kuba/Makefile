CFILES = add_to_output.c count_def_len.c count_nbr_char.c count_row_num.c create_triplet.c empty.c fill_matrix.c find_num.c find_ten_power.c ft_putstr.c ft_strcmp.c generate_matrix.c get_def_len_array.c get_file_size.c get_num_def.c gen_num.c get_str_len.c print_numbers.c print_result.c
  
OFILES = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME) clean

$(NAME): $(OFILES)
     ar rcs $(NAME) $(OFILES) 

clean:
  rm -f $(OFILES)

fclean:  
  clean rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re