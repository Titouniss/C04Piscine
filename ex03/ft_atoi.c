int	check_digit(char c)
{
	if(c >= '0' && c <= '9' )
		return(1);
	return(0);
}

int ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int ft_atoi(char *str)
{
	int i;
	int sign;
	int res;
	
	res = 0;	
	i = 0;
	sign = 1;

	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] != '-' && str[i] != '+' && check_digit(str[i]) == 0)
		return (0);

	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	if (check_digit(str[i]) == 0)
		i++;

	while (check_digit(str[i]) == 1)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
