#include <unistd.h>

static int	ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	unsigned char	c;
	char		*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			c = (unsigned char)str[i];
			ft_putchar(hex[(c >> 4) & 0xF]);
			ft_putchar(hex[c & 0xF]);
		}
		i++;
	}
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buf[1024];
	size_t	len;

	printf("Enter a string:\n");
	fgets(buf, sizeof(buf), stdin);
	len = strlen(buf);
	if (len > 0 && buf[len - 1] == '\n')
		buf[len - 1] = '\0';
	ft_putstr_non_printable(buf);
	printf("\n");
	return (0);
}
