#include "get_next_line.h"

static char	*ft_read_fd(int fd, int *nbr_to_cpy)
{
	char	*str;
	char	buf[BUFFER_SIZE];
	int		nb_cara_read;
	int		i;
	int		flag_nl;

	if (fd < 0)
		return (NULL);
	nb_cara_read = read(fd, buf, BUFFER_SIZE);
	if (nb_cara_read <= 0)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * nb_cara_read);
	flag_nl = 0;
	while (i <= nb_cara_read)
	{
		str[i] = buf[i];
		if (str[i] != '\n' && flag_nl == 0)
			*nbr_to_cpy = i;
		else if (str[i] == '\n')
			flag_nl = 1;
		i++;
	}
	return (str);
}
/*
static void	ft_clean_line(char **str)
{

}
*/
char	*get_next_line(int fd)
{
	static char *str_mem;
	char		*str_final_cut;
	int			nbr_to_cpy;
	int			str_ready;

	str_final_cut = NULL;
	str_ready = 1;
	while (str_ready)
	{
		str_mem = ft_read_fd(fd, &nbr_to_cpy);
	//	printf("str_mem recu:%s - nbr_to_cpy:%d\n", str_mem, nbr_to_cpy);
		if (str_mem == NULL)
			break ;
		if (!str_final_cut)
			str_final_cut = (char *)malloc(sizeof(char) * nbr_to_cpy + 1);
		if (!str_final_cut)
			return (NULL);
		str_final_cut = ft_strjoin(str_final_cut, str_mem, nbr_to_cpy);
	//	ft_clean_line(str_mem);
	//	printf("str_final_cut:%s\n", str_final_cut);

	}
	return (str_final_cut);
}
