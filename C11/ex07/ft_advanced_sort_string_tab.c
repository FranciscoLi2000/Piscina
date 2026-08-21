
static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	tab_len(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		len;
	int		i;
	int		j;
	char	*tmp;

	len = tab_len(tab);
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_string_tab(char **tab)
{
	ft_advanced_sort_string_tab(tab, ft_strcmp);
}
