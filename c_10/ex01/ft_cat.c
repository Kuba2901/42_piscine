#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void ft_putstr(char *str) {
	while (*str) {
		write(1, str, 1);
		str++;
	}
}

void display_file(char *file_name) {
	int file;
	char c;

	file = open(file_name, O_RDONLY);
	if (file == -1) {
		// char *base_name = basename(file_name);
		// ft_putstr(base_name);
		// ft_putstr(": ");
		ft_putstr("ft_cat: ");
		ft_putstr(file_name);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		return;
	}
	while (read(file, &c, 1))
		write(1, &c, 1);
	close(file);
}

void display_files(int ac, char **av) {
	int i;

	i = 0;
	while (++i < ac)
		display_file(av[i]);
}

int main(int ac, char **av) {
	display_files(ac, av);
	return 0;
}
