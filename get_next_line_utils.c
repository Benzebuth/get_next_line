#include "get_next_line.h"

char    *ft_read_fd(int fd)
{
        char    *str;
        char    buf[BUFFER_SIZE + 1];
        int             nb_cara_read;
        int             i;

        if (fd < 0)
                return (NULL);
        nb_cara_read = read(fd, buf, BUFFER_SIZE);
        if (nb_cara_read <= 0)
                return (NULL);
        str = (char *)malloc(sizeof(char) * nb_cara_read);
		if (!str)
			return (NULL);
        i = 0;
        while (i < nb_cara_read)
        {
                str[i] = buf[i];
                i++;
        }
		str[i] = '\0';
	//	printf("out of ft_read_fd:%s:\n", str); OK
        return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;


	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_cut_nl(char *str)
{
	char	*dest;
	int		i;
	int		j;
	int		dest_size;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	dest_size = ft_strlen(str) - i;
	if (i == ft_strlen(str))
		return (str);
//	printf("ici%d\n",(ft_strlen(str) - i));
	dest = (char *)malloc(sizeof(char) * dest_size + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (str[++i])
		dest[j++] = str[i];
	dest[j] = '\0';
//	printf("ouf  of ft_cut_nl:%s:\n", dest);
	return (dest);
}
