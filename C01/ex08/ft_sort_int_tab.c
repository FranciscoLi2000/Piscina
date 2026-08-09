
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int	tab[] = {3, 8, 9, 1, 2};

	ft_sort_int_tab(tab, 5);
	for (int i = 0; i < 5; i++)
		printf("%i ", tab[i]);
	printf("\n");
	return (0);
}
