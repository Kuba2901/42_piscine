void	get_num(int file, int row_nb, char ***mat)
{
	int	i;
	int	num;
	char buff;
	int	ignoring;

	i = 0;
	num = 0;
	ignoring = 0;
	while (read(file, &buff, 1))
	{
		if (buff == '\n')
		{
			if (ignoring)
				mat[i++][0][num] = '\0';
			ignoring = 0;
			num = 0;
		}
		if (buff == ':')
			ignoring = 1;
		if (!ignoring && buff != ' ' && buff != '\n')
			mat[i][0][num++] = buff;
	}
	close(file);
}