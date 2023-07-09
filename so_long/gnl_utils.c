#include "so_long.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[len] = 0;
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

char	*reallocbuff(char *buff, int rv)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (rv + 1));
	if (!tmp)
		return (NULL);
	while (i < rv)
	{
		tmp[i] = buff[i];
		i++;
	}
	tmp[i] = 0;
	free(buff);
	return (tmp);
}
