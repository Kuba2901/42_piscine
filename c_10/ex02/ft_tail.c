#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int	ft_atoi(char *str);
int count_chars(char *file_name);
int	can_be_opened(char *file_name);
void read_tail(char *file_name, int char_num);
void ft_putstr(char *str);

void display_files(int ac, char **av, int char_num) {
	int i;

	i = 2;
	while (++i < ac)
	{
		if (ac > 4 && can_be_opened(av[i]))
		{
			if (i == 3)
				ft_putstr("==>");
			else
				ft_putstr("\n==>");
			ft_putstr(av[i]);
			ft_putstr("<==\n");
		}
		read_tail(av[i], char_num);
	}
}

int main(int ac, char **av) {
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		ft_putstr("ft_tail: option requires an argument -- c\n");
		return (0);
	}
	if (ac == 3)
		return (0);
	display_files(ac, av, ft_atoi(av[2]));
	return 0;
}
