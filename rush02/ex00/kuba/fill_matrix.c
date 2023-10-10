#include <fcntl.h>

void	fill_matrix(const char *file_name, char ***matrix)
{
	int	file;

	file = open(file_name, O_RDONLY);
	get_num(file_name, count_row_num(file_name), matrix);
	file = open(file_name, O_RDONLY);
	get_num_def(file, count_row_num(file_name), matrix);
}