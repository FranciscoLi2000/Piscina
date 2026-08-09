#include <unistd.h>
/*
static void	print_nbr(int nbr)
{
	char	c;

	c = (nbr / 10) + '0';
	write(1, &c, 1);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}
*/
static void	print_combi(int *arr, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

static void	ft_recurse(int *arr, int index, int n, int start, int *first)
{
	int	i;

	if (index == n)
	{
		if (*first == 0)
			write(1, ", ", 2);
		else
			*first = 0;
//		i = 0;
//		while (i < n)
//		{
		print_combi(arr, n);
//			i++;
//		}
		return ;
	}
	i = start;
	while (i <= 9)
	{
		arr[index] = i;
		ft_recurse(arr, index + 1, n, i + 1, first);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[9];
	int	first;

	if (n <= 0 || n >= 10)
		return ;
	first = 1;
	ft_recurse(arr, 0, n, 0, &first);
	write(1, "\n", 1);
}
#include <stdio.h>
int	main(void)
{
	int	i;

	printf("Enter a number:\n");
	scanf("%i", &i);
	ft_print_combn(i);
	return (0);
}
