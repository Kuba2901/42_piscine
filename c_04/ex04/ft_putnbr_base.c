#include <unistd.h>

int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	str_cmp_simple(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (get_str_len(s1) != get_str_len(s2))
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	get_str_base(char *base)
{
	if (!str_cmp_simple(base, "0123456789ABCDEF"))
		return (16);
	if (!str_cmp_simple(base, "0123456789"))
		return (10);
	if (!str_cmp_simple(base, "poneyvif"))
		return (8);
	if (!str_cmp_simple(base, "01"))
		return (2);
	return (0);

}

void    ft_put_str(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void	ft_putnbr_base(int nb, char *base)
{
    char    a;
    int     base_num;
    
	if (!get_str_base(base))
	{
		ft_put_str("wrong base");
		return ;
	}
	base_num = get_str_base(base);
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		ft_putnbr_base(147483648, base_num);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nb, base_num);
	}
	else if (nb <= base_num - 1)
	{
		a = "0123456789ABCDEF"[nb];
		write(1, &a, 1);
	}
	else
	{
		ft_putnbr_base(nb / base_num, base);
		ft_putnbr_base(nb % base_num, base);
	}
}

int main(void)
{
    ft_putnbr_base(100, "0123456789");
    return (0);
}

