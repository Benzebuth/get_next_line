/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcolin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:57:48 by bcolin            #+#    #+#             */
/*   Updated: 2021/10/27 19:24:12 by bcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read_fd(int fd, int *eof)
{
        char    *str;
        char    buf[BUFFER_SIZE + 1];
        int		nb_cara_read;
        int		i;

        if (fd < 0)
                return (NULL);
        nb_cara_read = read(fd, buf, BUFFER_SIZE);
        if (nb_cara_read <= 0)
		{
			*eof = 1; // et apres ?
            return (NULL);
		}
        str = (char *)malloc(sizeof(char) * nb_cara_read + 1);
		if (!str)
			return (NULL);
        i = 0;
        while (i < nb_cara_read)
        {
                str[i] = buf[i];
                i++;
        }
		str[i] = '\0';
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

	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (s2);
	}
	if (!s2)
		return (s1);
	if (ft_strlen(s1) + ft_strlen(s2) == 0)
		return (NULL);
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
	free(s2);
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
	dest_size = (ft_strlen(str) - i) - 1;
	//if (dest_size == 0)
	//{
	//	free(str);
	//	return (NULL);
	//}
	if (i == ft_strlen(str))
		return (str);
	dest = (char *)malloc(sizeof(char) * dest_size + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (str[++i])
		dest[j++] = str[i];
	dest[j] = '\0';
	free(str);
	return (dest);
}
