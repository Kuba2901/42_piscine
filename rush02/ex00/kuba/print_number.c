int    number_empty(char *nbr)
{
    if (empty(nbr))
	{
		put_str("zero");
		return (1);
	}
    return (0);
}

int number_less_than_4_digits(char *nbr, char ***mat)
{
    char dest[4];
	char output[64][1024];
    int	output_index;
	int	i;

    i = 0;
	output_index = 0;
    if (get_str_len(nbr) < 4)
	{
		create_triplet(nbr, i, dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(output, output_index++, get_string_triplet(dest, mat));
			print_result(output,  output_index);
		}
		return (1);
	}
	return (0);
}

int	only_triplets(char *nbr, char output[64][1024], char ***mat, int *output_index, int row_num)
{
	char dest[4];
	int first_trip;
	int i;

	i = 0;
	first_trip = get_str_len(nbr) % 3;
	if (!first_trip)
	{
		// CALL GET_STRING_TRIPLET
		create_triplet(nbr, i, dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(output, output_index, get_string_triplet(dest, mat));
			*output_index += 1;
			i += 3;
			add_to_output(output, output_index++, find_ten_power(nbr, i, mat, row_num));
			*output_index += 1;
			return (i);
		}
	}
	return (0);
}

int	first_not_triplet(char *nbr, char output[64][1024], char ***mat, int *output_index, int row_num, int i)
{
	int	first_trip;
	char dest[4];

	first_trip = get_str_len(nbr) % 3;
	if (first_trip)
	{
		create_triplet(nbr, i, dest);
		printf("dest: %s\n", dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(output, *output_index, get_string_triplet(dest, mat));
			*output_index += 1;
			add_to_output(output, output_index, find_ten_power(nbr, i + first_trip, mat, row_num));
			*output_index += 1;
		}
	}
}

void    print_number(char *nbr, char ***mat, int row_num)
{
    int i;
    int first_trip;
    char dest[4];
	char output[64][1024];
	int	numbers_left;
	int	output_index;

	if (number_empty(nbr))
        return ;
    i = 0;
	output_index = 0;
    first_trip = get_str_len(nbr) % 3;
	if (number_less_than_4_digits(nbr, mat))
		return ;
	i += only_triplets(nbr, output, mat, output_index, row_num);
	if (first_trip != 2)
		while (i < first_trip - 1)
			i++;
	first_not_triplet(nbr, output, mat, &output_index, row_num, i);
	while (i < first_trip)
		i++;
	while (i < get_str_len(nbr) - 3)
	{
		create_triplet(nbr, i, dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(output, output_index++, get_string_triplet(dest, mat));
			i += 3;
			add_to_output(output, output_index++, find_ten_power(nbr, i, mat, row_num));
		}
		else
			i += 3;
	}
	create_triplet(nbr, i, dest);
	add_to_output(output, output_index++, get_string_triplet(dest, mat));
	print_result(output, output_index);
}