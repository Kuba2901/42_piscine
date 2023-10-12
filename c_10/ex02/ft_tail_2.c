#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void ft_putstr(char *str) {
	while (*str) {
		write(1, str, 1);
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	num;
	int	minus_count;

	num = 0;
	minus_count = 0;
	while (*str < '0' || *str > '9')
	{
		if (*str != '-' && *str != ' ' && *str != '+')
			return (0);
		if (*str == '-')
			minus_count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (minus_count % 2 != 0)
		return (-num);
	return (num);
}

int count_chars(char *file_name)
{
	int file;
	int counter;
	char c;

	file = open(file_name, O_RDONLY);
	if (file == -1) {
		ft_putstr("ft_tail: ");
		ft_putstr(file_name);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		return (-1);
	}
	counter = 0;
	while (read(file, &c, 1))
		counter++;
	close(file);
	return (counter);
}

int	can_be_opened(char *file_name)
{
	int	file;

	file = open(file_name, O_RDONLY);
	if (file == -1)
	{
		close(file);
		return (0);
	}
	close(file);
	return (1);
}

void read_tail(char *file_name, int char_num) {
	int file;
	char c;
	int chars_count;
	int	counter;

	chars_count = count_chars(file_name);
	if (chars_count < 0)
		return ;
	file = open(file_name, O_RDONLY);
	counter = 0;
	while (read(file, &c, 1))
	{
		if (chars_count - char_num - counter <= 0)
			write(1, &c, 1);
		counter++;
	}
	close(file);
}
