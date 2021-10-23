#include "get_next_line.h"

int	main(void)
{
	char	*recu;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("error fd loading\n");
		return (1);
	}
	recu = get_next_line(fd);
	printf("%s", recu);

	/*
	while (1)
	{
		recu = get_next_line(fd);
		printf("%s", recu);
		if (recu == NULL)
			break ;
	}
	*/
	return (0);
}
