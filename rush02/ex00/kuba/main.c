#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/***
 * TODO: LIST
 * 1. Protect input - has to behave like atoi
 * 2. Protect when value wasn't found in the dictionary
 * 3. Check if memory is freed when not needed
 * 4. Handle input (giving a new dictionary)
 * 5. Error on negative numbers
 * 6. Handle empty definitions
 * 7. "If you have any errors from the dictionary parsing, your program must output "Dict Error\n"
 * 8. "If the dictionary doesn’t allow you to resolve the asked value, your program must output "Dict Error\n"."" 
 * 9. Write the makefile according to the subject
***/

int count_def_len(int file);
int *get_def_len_arr(const char *file_name, int row_num);
int get_file_size(const char *path);
int count_row_num(const char *path);
int	*count_nbr_char(const char *path);
char	***generate_matrix(const char *path);
void	get_num_def(int file, int row_nb, char ***mat);
int	ft_strcmp(char *s1, char *s2);
char	*find_num(char *num, int row_nb, char ***mat);
void	get_num(int file, int row_nb, char ***mat);
void	fill_matrix(const char *file_name, char ***matrix);

//DEBUG--------------------------------------------------------------------
#include <stdio.h>
void	print_mat(char ***mat, int row_nb)
{
	int	i;

	i = 0;
	while (i < row_nb)
	{
		printf("%s:%s", mat[i][0], mat[i][1]);
		i++;
	}
}
//DEBUG--------------------------------------------------------------------

char *create_string_gst(int keys[3], int hdu[3], char ***mat)
{
	char 	*ret;
	int		i;
	int		j;
	int		k;
	char	*hundred;
	
	hundred = "hundred";
	ret = malloc(1000);
	i = -1;
	k = 0;
	while (++i < 3)
	{
		if (hdu[i])
		{
			j = -1;
			while (mat[keys[i]][1][++j])
			{
				ret[k++] = mat[keys[i]][1][j];
			}
			ret[k++] = ' ';
		}
		if (i == 0 && hdu[0])
		{
			j = -1;
			while (hundred[++j])
				ret[k++] = hundred[j];
			ret[k++] = ' ';
		}
	}
	ret[--k] = '\0';
	return (ret);
}

char *get_string_triplet(char *triplet, char ***mat)
{
	int		keys[3];
	int		hdu[3];
	int		i;
	int		j;
	char	t[3];

	i = -1;
	while (++i < 3)
	{
		if (triplet[i] == '0')
		{
			hdu[i] = 0;
			continue;
		}
		else
			hdu[i] = 1;
		if (i == 0 || i == 2)
		{
			t[0] = triplet[i];
			t[1] = '\0';
			j = 0;
			while (ft_strcmp(t, mat[j][0]))
				j++;
			keys[i] = j;
		}
		if (i == 1)
		{
			if (triplet[i] == '1')
			{
				t[0] = triplet[i];
				t[1] = triplet[i + 1];
				t[2] = '\0';
				j = 0;
				while (ft_strcmp(t, mat[j][0]))
					j++;
				keys[i] = j;
				hdu[2] = 0;
				break;
			}
			else
			{
				t[0] = triplet[i];
				t[1] = '0';
				t[2] = '\0';
				j = 0;
				while (ft_strcmp(t, mat[j][0]))
					j++;
				keys[i] = j;
			}
		}
	}
	return (create_string_gst(keys, hdu, mat));
}

int get_str_len(char *str);
char	*find_ten_power(char *nbr, int i, char ***mat, int row_num);
void	put_str(char *str);
void	create_triplet(char *nbr, int i, char dest[4]);
void	add_to_output(char output[64][1024], int output_index, char *str);
void	print_result(char output[64][1024], int output_index);
int	empty(char *str);

void    print_number(char *nbr, char ***mat, int row_num)
{
    int i;
    int first_trip;
    char dest[4];
	char output[64][1024];
	int	numbers_left;
	int	output_index;

	if (empty(nbr))
	{
		put_str("zero");
		return ;
	}
    i = 0;
	output_index = 0;
    first_trip = get_str_len(nbr) % 3;
	if (get_str_len(nbr) < 4)
	{
		create_triplet(nbr, i, dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(output, output_index++, get_string_triplet(dest, mat));
			print_result(output,  output_index);
		}
		return ;
	}
	if (!first_trip)
	{
		// CALL GET_STRING_TRIPLET
		create_triplet(nbr, i, dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(output, output_index++, get_string_triplet(dest, mat));
			i += 3;
			add_to_output(output, output_index++, find_ten_power(nbr, i, mat, row_num));
		}
	}
	if (first_trip != 2)
		while (i < first_trip - 1)
			i++;
	// CALL GET_STRING_TRIPLET
	if (first_trip)
	{
		create_triplet(nbr, i, dest);
		printf("dest: %s\n", dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(output, output_index++, get_string_triplet(dest, mat));
			add_to_output(output, output_index++, find_ten_power(nbr, i + first_trip, mat, row_num));
		}
	}
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

int main(int argc, char **argv)
{
	char	*dict_path = "numbers.dict";
	char ***mat = generate_matrix(dict_path);
	char	*number;

	if (argc == 2)
		number = argv[1];
	else if (argc == 3)
	{
		number = argv[2];
		dict_path = argv[1];
	}

	fill_matrix(dict_path, mat);
	int	row_nb = count_row_num(dict_path);
	fill_matrix(dict_path, mat);
	print_number(argv[1], mat, count_row_num(dict_path));
}
