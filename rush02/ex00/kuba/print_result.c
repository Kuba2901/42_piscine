void	print_result(char output[64][1024], int output_index)
{
	int	i;

	i = 0;
	while (i < output_index)
	{
		put_str(output[i]);
		put_str(" ");
		i++;
	}
}