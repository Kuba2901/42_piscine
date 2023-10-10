#include <stdlib.h>

char	***generate_matrix(const char *path)
{
	char	***mat;
	int		row_nb;
	int		*char_lens[2];
	int		i;

	row_nb = count_row_num(path);
	char_lens[0] = count_nbr_char(path);
	char_lens[1] = get_def_len_arr(path, row_nb);
	mat = malloc(row_nb * sizeof(char **));
	i = -1;
	while (++i < row_nb)
	{
		mat[i] = malloc(2 * sizeof(char *));
		mat[i][0] = calloc(char_lens[0][i] + 1, sizeof(char));
		mat[i][1] = calloc(char_lens[1][i] + 1, sizeof(char));
	}
	free(char_lens[0]);
	free(char_lens[1]);
	return (mat);
}