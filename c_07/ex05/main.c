#include <stdio.h>
#include <stdlib.h>

int is_sep(char *str, char *charset);
int count_words(char *str, char *charset);
char **ft_split(char *str, char *charset);

int main()
{
    char *str = "This  is a test string";
    char *charset = "t";

    char **result = ft_split(str, charset);
    return 0;
}

