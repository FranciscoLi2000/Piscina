
int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	int	n;

	printf("Enter a number:\n");
	scanf("%i", &n);
	if (ft_is_prime(n))
		printf("%i is a primer number\n", n);
	else
		printf("%i is a NOT primer number\n", n);
	return (0);
}
