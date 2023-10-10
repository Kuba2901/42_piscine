void	create_triplet(char *nbr, int i, char dest[4])
{
	int trip_len;
	int	j;

	trip_len = get_str_len(nbr) % 3;
	j = 0;
	if (i < trip_len)
		while (j < (3 - trip_len))
			dest[j++] = '0';
	while (j < 3)
		dest[j++] = nbr[i++];
	dest[j] = '\0';
}