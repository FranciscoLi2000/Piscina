
static int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isalnum(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	new_word = 1;
	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			new_word = 1;
		else
		{
			if (new_word == 1 && ft_isalpha(str[i]))
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] = str[i] - 'a' + 'A';
			}
			else if (ft_isalpha(str[i]))
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] = str[i] - 'A' + 'a';
			}
			new_word = 0;
		}
		i++;
	}
	return (str);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buf[1024];
	size_t	len;

	printf("enter a string:\n");
//	scanf("%s", buf);
	
	fgets(buf, sizeof(buf), stdin);
	len = strlen(buf);
	if (len > 0 && buf[len - 1] == '\n')
		buf[len - 1] = '\0';

	printf("%s\n", ft_strcapitalize(buf));
	return (0);
}
