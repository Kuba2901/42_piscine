#include <stdlib.h>

char	*find_num(char *num, int row_nb, char ***mat)
{
	char *s1;
	int	i;

	i = 0;
	while (i < row_nb)
	{
		s1 = mat[i][0];
		if (!ft_strcmp(s1, num))
			return (mat[i][1]);
		i++;
	}
    return (NULL);
}