#include "get_next_line.h"

int	main(void)
{
	char	*recu;
	int		fd;

	fd = open("gnlTester/files/42_no_nl", O_RDONLY);
	if (fd < 0)
	{
		printf("error fd loading\n");
		return (1);
	}
	
	recu = get_next_line(fd);
	printf("%s", recu);
	free(recu);

	recu = get_next_line(fd);
	printf("%s", recu);
	if (recu)
		free(recu);
/*
	recu = get_next_line(fd);
	printf("%s", recu);
	if (recu)
		free(recu);
	recu = get_next_line(fd);
	printf("%s", recu);
	if (recu)
		free(recu);
	recu = get_next_line(fd);
	printf("%s", recu);
	if (recu)
		free(recu);
	recu = get_next_line(fd);
	printf("%s", recu);
	if (recu)
		free(recu);
	recu = get_next_line(fd);
	printf("%s", recu);
	if (recu)
		free(recu);
	recu = get_next_line(fd);
	printf("%s", recu);
	if (recu)
		free(recu);
	recu = get_next_line(fd);
	printf("%s", recu);
	if (recu)
		free(recu);
	recu = get_next_line(fd);
	printf("%s", recu);
	if (recu)
		free(recu);
*/

	/*
	while (1)
	{
		recu = get_next_line(fd);
		printf("out:%s", recu);
		if (recu == NULL)
			break ;
		else
			free(recu);
	}
	*/
	return (0);
}
