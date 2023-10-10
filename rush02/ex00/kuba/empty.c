int	empty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
		if (str[i++] != '0')
			return (0);
	return (1);
}