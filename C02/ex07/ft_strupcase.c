
int	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_toupper(str[i]);
		i++;
	}
}
