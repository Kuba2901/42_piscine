int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			ret += (unsigned char)s1[i] - (unsigned char)s2[i];
			break ;
		}
		i++;
	}
	if (s1[i] == '\0')
		ret += (unsigned char)s1[i] - (unsigned char)s2[i];
	return (ret);
}