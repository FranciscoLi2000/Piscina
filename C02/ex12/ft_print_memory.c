#include <unistd.h>

static void	ft_putaddr(unsigned long addr)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		write(1, &base[(addr >> (i * 4)) & 0xf], 1);
		i--;
	}
}

static void	ft_puthex(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

static void	ft_print_hex(unsigned char *p, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < len)
			ft_puthex(p[i]);
		else
			write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

static void	ft_print_ascii(unsigned char *p, unsigned int len)
{
	unsigned int	i;
	char		c;

	i = 0;
	while (i < len)
	{
		c = p[i];
		if (c < 32 || c > 126)
			c = '.';
		write(1, &c, 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*p;
	unsigned int	len;

	p = (unsigned char *)addr;
	while (size > 0)
	{
		len = size;
		if (len > 16)
			len = 16;
		ft_putaddr((unsigned long)p);
		write(1, ": ", 2);
		ft_print_hex(p, len);
		ft_print_ascii(p, len);
		write(1, "\n", 1);
		p += 16;
		size -= len;
	}
	return (addr);
}
#include <string.h>
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_print_memory(argv[1], strlen(argv[1]));
	return (0);
}
