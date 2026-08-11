
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!find[0])
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (!to_find[j])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
