void	put_str(char *str)
{
	int i;

	i = 0;
    if (!str)
        return ;
	while (str[i])
		write(1, &str[i++], 1);
}