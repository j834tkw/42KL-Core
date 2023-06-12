#include "get_next_line.h"

char	*ft_readfile(int fd, char *buffer)
{
	int		bytes;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		tmp[bytes] = 0;
		buffer = ft_strjoin_free(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*ft_getline(char *buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	tmp = (char *)malloc((i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		tmp[j++] = buffer[i++];
	if (buffer[i] == '\n')
		tmp[j++] = buffer[i];
	tmp[j] = 0;
	return (tmp);
}

char	*ft_cleanup(char *buffer)
{
	char	*tmp;
	int		i;
	int		j;

	j = ft_strlen_gnl(buffer);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	tmp = (char *)malloc((j - i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i] != '\0')
		tmp[j++] = buffer[i++];
	tmp[j] = 0;
	free(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer && read(fd, 0, 1) == 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1 * sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = 0;
	}
	buffer = ft_readfile(fd, buffer);
	if (buffer[0] == 0)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_getline(buffer);
	buffer = ft_cleanup(buffer);
	return (line);
}
