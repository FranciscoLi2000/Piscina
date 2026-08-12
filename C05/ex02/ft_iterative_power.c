
int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	j;

	if (power < 0)
		return (0);
	if (power == 0 || nb == 0)
		return (1);
	i = 0;
	j = nb;
	while (i < power)
	{
		nb = nb * j;
		i++;
	}
	return (nb);
}
