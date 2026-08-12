
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}

#include <stdio.h>

int	main(void)
{
	int	n;

	printf("Enter a number:\n");
	scanf("%i", &n);
//	if (ft_is_prime(n))
//		printf("%i is a primer number\n", n);
//	else
//		printf("%i is a NOT primer number\n", n);
	printf("The next prime number is %i\n", ft_find_next_prime(n));
	return (0);
}
