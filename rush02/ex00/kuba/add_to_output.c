void	add_to_output(char output[64][1024], int output_index, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		output[output_index][i] = str[i];
		i++;
	}
}