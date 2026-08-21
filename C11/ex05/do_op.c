#include <unistd.h>

static void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	result = 0;
	while (is_digit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static int	ft_add(int a, int b)
{
	return (a + b);
}

static int	ft_sub(int a, int b)
{
	return (a - b);
}

static int	ft_mul(int a, int b)
{
	return (a * b);
}

static int	ft_div(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	return (a / b);
}

static int	ft_mod(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	return (a % b);
}

static int	handle_op(char op, int a, int b, int *error)
{
	char	ops[5];
	int		(*funcs[5])(int, int);
	int		i;

	ops[0] = '+';
	ops[1] = '-';
	ops[2] = '*';
	ops[3] = '/';
	ops[4] = '%';
	funcs[0] = ft_add;
	funcs[1] = ft_sub;
	funcs[2] = ft_mul;
	funcs[3] = ft_div;
	funcs[4] = ft_mod;
	i = 0;
	while (i < 5)
	{
		if (ops[i] == op)
		{
			if ((op == '/' || op == '%') && b == 0)
				*error = 1;
			return (funcs[i](a, b));
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	int		result;
	int		error;

	if (argc != 4)
		return (0);
	if (argv[2][0] == '\0' || argv[2][1] != '\0')
	{
		ft_putnbr(0);
		write(1, "\n", 1);
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	error = 0;
	result = handle_op(argv[2][0], a, b, &error);
	if (error)
		return (0);
	if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' && argv[2][0] != '/' && argv[2][0] != '%')
	{
		ft_putnbr(0);
		write(1, "\n", 1);
		return (0);
	}
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
