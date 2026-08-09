#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n >= 0)
		write(1, "P", 1);
	else
		write(1, "N", 1);
}
#include <stdio.h>
int	main(void)
{
	int	nb;

	printf("Enter a number:\n");
	scanf("%i", &nb);
	ft_is_negative(nb);
	return (0);
}
