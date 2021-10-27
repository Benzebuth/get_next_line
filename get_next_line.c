/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcolin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:56:32 by bcolin            #+#    #+#             */
/*   Updated: 2021/10/27 19:16:29 by bcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// ATTENTION CONTIENT LE BONUS A DUPLIQUER ET TRAITER
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
	static char *str_mem[4096];
	char		*str_mem_next[4096];
	char		*str_final_cut;
	int			str_ready;
	int			eof;

	if (read(fd, 0, 0))
		return (NULL);
	eof = 0;
	str_ready = 1;
	if (!str_mem[fd])
		str_mem[fd] = ft_read_fd(fd, &eof);
	while (str_ready)
	{
		str_mem_next[fd] = ft_read_fd(fd, &eof);
		if (str_mem_next[fd] == NULL)
			str_ready = 0;
		str_final_cut =	ft_nl_test(str_mem[fd], &str_ready);
		str_mem[fd] = ft_cut_nl(str_mem[fd]);
		str_mem[fd] = ft_strjoin(str_mem[fd], str_mem_next[fd]);
	}
	return (str_final_cut);
}
