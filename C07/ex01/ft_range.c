#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
