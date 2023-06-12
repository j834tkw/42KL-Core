#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

char	*get_next_line(int fd);

char	*ft_readfile(int fd, char *buffer);

char	*ft_getline(char *buffer);

char	*ft_cleanup(char *buffer);

size_t	ft_strlen_gnl(const char *str);

char	*ft_strdup(char *s);

int		ft_strchr(char *str, int c);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strjoin_free(char *s1, char *s2);

char	*ft_redeploy(char *s, int len);

#endif
