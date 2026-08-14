#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	return_length(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = -1;
	len = size_sep * -1;
	while (i < size)
	{
		len += size_sep + ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		*dest = src[i];
		i++;
		dest++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		len;

	if (size == 0)
	{
		res = (char *)malloc(1);
		return (res);
	}
	len = return_length(size, strs, ft_strlen(sep));
	i = -1;
	if ((res = malloc((len + 1) * sizeof(char))) == NULL)
		return (0);
	while (i < size)
	{
		res = ft_strcpy(res, strs[i]);
		if (i + 1 < size)
			res = ft_strcpy(res, sep);
		i++;
	}
	*res = '\0';
	return (res - len);
}
