
int	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_tolower(str[i]);
		i++;
	}
}
