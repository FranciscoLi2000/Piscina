
static int	check_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) || (c >= 'a' && c <= ('a' + base - 10)));
}

int	ft_atoi_base(char *str, int base)
{
	int	res;
	int	i;
	int	sign;

	if (!str[0] || (base < 2 || base > 16))
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && check_base(str[i], base))
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			res = res * base + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res * base + (str[i] - 'a' + 10);
		else
			res = res * base + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
