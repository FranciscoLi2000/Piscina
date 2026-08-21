#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*res;

	res = malloc(length * sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	while (i < length)
	{
		res[i] = tab[i];
		i++;
	}
	return (res);
}
