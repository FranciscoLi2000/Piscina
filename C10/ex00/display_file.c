#include "display_file.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_putstr(NO_ARG_MSG);
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr(MORE_THAN_ONE_MSG);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(CANNOT_READ_MSG);
		return (1);
	}
	close(fd);
	return (0);
}
