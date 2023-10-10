#include <stdlib.h>

char	*find_ten_power(char *nbr, int i, char ***mat, int row_num)
{
    int     pow;
    int     j;
    char    *str;

    pow = 1;
    while (nbr[i])
    {
        i++;
        pow++;
    }
    str = malloc(pow + 1);
    j = 0;
    while (j < pow)
    {
        if (j == 0)
            str[j] = '1';
        else
            str[j] = '0';
        j++;
    }
	str[j] = '\0';
    return (find_num(str, row_num, mat));
}