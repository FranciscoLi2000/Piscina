#include "ft_stock_str.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *str)
{
	char	*copy;
	int		i;
	int		len;

	len = ft_strlen(str);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	ft_free_tab(t_stock_str *tab, int until)
{
	int	i;

	i = 0;
	while (i < until)
	{
		free(tab[i].str);
		free(tab[i].copy);
		i++;
	}
	free(tab);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;
	int			len;

	if (ac < 0)
		return (NULL);
	tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		tab[i].size = len;
		tab[i].str = ft_strdup(av[i]);
		tab[i].copy = ft_strdup(av[i]);
		if (!tab[i].str || !tab[i].copy)
		{
			free(tab[i].str);
			free(tab[i].copy);
			ft_free_tab(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[ac].str = 0;
	tab[ac].copy = 0;
	tab[ac].size = 0;
	return (tab);
}
