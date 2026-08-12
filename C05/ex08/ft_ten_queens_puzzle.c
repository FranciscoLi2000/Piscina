#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	is_safe(int *rows, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (rows[i] == row)
			return (0);
		if (rows[i] - i == row - col)
			return (0);
		if (rows[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

static void	print_solution(int *rows)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(rows[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

static int	ft_place_queen(int *rows, int col)
{
	int	row;
	int	count;

	if (col == 10)
	{
		print_solution(rows);
		return (1);
	}
	count = 0;
	row = 0;
	while (row < 10)
	{
		if (is_safe(rows, col, row))
		{
			rows[col] = row;
			count += ft_place_queen(rows, col + 1);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	rows[10];

	return (ft_place_queen(rows, 0));
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	main(void)
{
	int	n;

	n = ft_ten_queens_puzzle();
	ft_putstr("\n******************\n");
	ft_putnbr(n);
	ft_putchar('\n');
	return (0);
}
