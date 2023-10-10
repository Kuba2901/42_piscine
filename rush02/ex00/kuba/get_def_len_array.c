#include <fcntl.h>

int *get_def_len_arr(const char *file_name, int row_num)
{
    int	*rows_def;
    int	file;
    int	i;
    int	row_len;
    int	temp_count;

    i = 0;
    file = open(file_name, O_RDONLY);
    if (file == -1)
        return 0;
    rows_def = (int *)malloc(row_num * sizeof(int));
    while (i < row_num)
    {
        temp_count = 0;
        row_len = count_def_len(file);
        while (!row_len)
        {
            row_len = count_def_len(file);
            temp_count++;
            if (temp_count > row_num)
                break ;
        }
        rows_def[i] = row_len;
        i++;
    }
    close(file);
    return (rows_def);
}