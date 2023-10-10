#include <fcntl.h>

void    reset_counters(int *num, int *counting, int *colon_found)
{
    *colon_found = 0;
    *counting = 0;
    *num = 0;
}

void	get_num_def(int file, int row_nb, char ***mat)
{
	int	i;
	int	num;
	char buff;
	int	counting;
	int	colon_found;

	i = 0;
    reset_counters(&num, &counting, &colon_found);
	while (read(file, &buff, 1))
	{
		if (buff == '\n')
		{
			if (colon_found)
				mat[i++][1][num] = '\0';
			reset_counters(&num, &counting, &colon_found);
		}
		if (buff == ':')
			colon_found = 1;
		else if (colon_found && buff != ' ')
			counting = 1;
		if (colon_found && counting && buff != '\n')
			mat[i][1][num++] = buff;
	}
	close(file);
}