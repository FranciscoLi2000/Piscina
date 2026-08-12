
int	ft_sqrt(int nb)
{
	int	i;

	i = 2;
	while (i * i <= nb && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int	i;
	int	st;

	printf("Enter a number:\n");
	scanf("%i", &i);
	st = ft_sqrt(i);
	if (!st)
		printf("Irrational\n");
	else
		printf("The root number is %i\n", st);
	return (0);
}
