
int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tab[i][0])
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}
