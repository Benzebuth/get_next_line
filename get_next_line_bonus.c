/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcolin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:56:32 by bcolin            #+#    #+#             */
/*   Updated: 2021/10/28 20:00:59 by bcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr_nl(char *str, int start_index, int len)
{
	char	*dest;
	int		i;

	if (!str)
		return (NULL);
	if (start_index > ft_strlen(str))
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = str[start_index + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_check_for_nl(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	append(char **memory, char *buffer, int read_count)
{
	char	*swp;

	if (!buffer)
		return ;
	buffer[read_count] = '\0';
	swp = ft_strjoin(*memory, buffer);
	free(*memory);
	*memory = swp;
}

static char	*gen_line(char **memory, int read_count)
{
	char	*ret;
	char	*swp;
	int		size;

	if (!**memory)
	{
		free(*memory);
		return (NULL);
	}
	size = ft_check_for_nl(*memory) + 1;
	if (size == 0)
		size = ft_strlen(*memory);
	ret = ft_substr_nl(*memory, 0, size);
	swp = ft_substr_nl(*memory, size, ft_strlen(*memory) - size);
	free(*memory);
	if (read_count == 0)
	{
		free(swp);
		*memory = NULL;
		return (ret);
	}
	*memory = swp;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*memory[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			index_nl;
	int			read_count;

	index_nl = -1;
	if (read(fd, 0, 0))
		return (NULL);
	while (1)
	{
		index_nl = ft_check_for_nl(memory[fd]);
		if (index_nl > -1)
			break ;
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == 0)
			break ;
		if (!memory[fd])
			memory[fd] = ft_substr_nl(buffer, 0, read_count);
		else
			append(&memory[fd], buffer, read_count);
	}
	if (!memory[fd])
		return (NULL);
	return (gen_line(&memory[fd], read_count));
}
