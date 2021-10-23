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
char	*ft_strjoin(char *s1, char *s2, int index_stop);

#endif
