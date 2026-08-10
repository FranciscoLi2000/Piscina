
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	ret;
	unsigned int	len;
	unsigned int	i;

	ret = 0;
	while (src[ret])
		ret++;
	if (size)
	{
		if (ret >= size)
			len = size - 1;
		else
			len = ret;
		i = 0;
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ret);
}
