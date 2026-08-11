#include <unistd.h>

static int	check_base(char *base)
{
	int	i;

	i = 0;
	if (!str[i] || !str[i + 1])
		return (0);
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	c;
	int		bs_num;

	bs_num = check_base(base);
	if (!bs_num)
		return ;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	else if (nb >= bs_num)
		ft_putnbr_base(nb / bs_num, base);
	c = nb % bs_num + '0';
	write(1, &c, 1);
}
