#include <fcntl.h>

int get_file_size(const char *path)
{
	int		file;
    int		len = 0;
    char 	buffer;

	file = open(path, O_RDONLY);
    while (read(file, &buffer, 1))
        	len++;
	close(file);
    return len;
}