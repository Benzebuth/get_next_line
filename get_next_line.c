#include "get_next_line.h"

static char	*ft_substr_nl(char *str, int i_start)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (i_start + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < i_start)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	if (str)
		free(str);
	return (new_str);
}

static char	*ft_nl_test(char *str, int *detected)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*detected = 0;
			i++;
			return (ft_substr_nl(str, i));
		}
		i++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char *str_mem = NULL;
	char		*str_mem_next;
	char		*str_final_cut;
	int			str_ready;

	if (!fd)
		return (NULL);
	str_ready = 1;
	if (!str_mem)
		str_mem = ft_read_fd(fd);
	while (str_ready)
	{
		str_mem_next = ft_read_fd(fd);
		if (str_mem_next == NULL)
			str_ready = 0;
		str_final_cut =	ft_nl_test(str_mem, &str_ready);
		str_mem = ft_cut_nl(str_mem);
		str_mem = ft_strjoin(str_mem, str_mem_next);
	}
	return (str_final_cut);
}
