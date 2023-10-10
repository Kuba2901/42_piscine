#include <fcntl.h>

int	*count_nbr_char(const char *path)
{
	int		file;
	char	buffer;
	int		tmp;
	int		*ret;
	int		i;

	i = 0;
	ret = malloc(count_row_num(path) * sizeof(int));
	tmp = 0;
	file = open(path, O_RDONLY);
	while (read(file, &buffer, 1))
	{
		if (buffer >= '0' && buffer <= '9')
			tmp++;
		else if (buffer == ':')
		{
			ret[i++] = tmp;
			tmp = 0;
		}
	}
	close(file);
	return (ret);
}