/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcolin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:20:39 by bcolin            #+#    #+#             */
/*   Updated: 2021/10/28 16:25:46 by bcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

//includes
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// DELETE THIS BEFORE FINAL PUSH
#include <stdio.h>

//prototype
char	*get_next_line(int fd);
int	    ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_fd(int fd, int *eof);
char	*ft_cut_nl(char *str);
void	ft_clean(char *str);

#endif
