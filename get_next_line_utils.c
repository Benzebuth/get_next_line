#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int index_stop)
{
	char	*dest;
	int		i;
	int		j;


	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + index_stop) + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = 0;
	while (s2[j] && j <= index_stop)
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
