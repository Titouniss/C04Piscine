void ft_putchar(char c)
{
	write(1, &c, 1);
}
int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);

	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])															
				return (0);	
			j++;
		}
		i++;
	}
	return(1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size_base;
	int	nbr_int[100];
	int	i;

	i = 0;
	size_base = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_int[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_int[i]]);
	}
}
