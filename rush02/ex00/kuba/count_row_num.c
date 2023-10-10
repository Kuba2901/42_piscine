#include <fcntl.h>

int count_row_num(const char *path)
{
	int		file;
    int		row_num = 0;
    char	buffer;

	file = open(path, O_RDONLY);
    while (read(file, &buffer, 1))
		if (buffer == '\n')
        	row_num++;
	close(file);
    return row_num + 1;
}