#include "get_next_line.h"

static char	*ft_read_fd(int fd)
{
	char	*str;
	char	buf[BUFFER_SIZE];
	int		nb_cara_read;
	int		i;

	if (fd < 0)
		return (NULL);
	nb_cara_read = read(fd, buf, BUFFER_SIZE);
	if (nb_cara_read <= 0)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * nb_cara_read);
	while (i <= nb_cara_read)
	{
		str[i] = buf[i];
		i++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char *str_mem;

	str_mem = ft_read_fd(fd);

	return (str_mem);
}
