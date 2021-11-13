#include "get_next_line.h"
#include <stdio.h>

int		main()
{
	int		fd;
	int		fd1;
	int		fd2;
	int		fd3;
	char	*str;

	fd = open("myfile.txt", O_RDONLY);
	fd1 = open("myfile.txt", O_RDONLY);
	fd2 = open("myfile.txt", O_RDONLY);
	fd3 = open("myfile.txt", O_RDONLY);
	str = get_next_line(fd);
	free(str);
	while (str != 0)
	{
		printf("%s", str);
		str = get_next_line(fd);
		free(str);
		printf("%s", str);
		str = get_next_line(fd1);
		free(str);
		printf("%s", str);
		str = get_next_line(fd2);
		free(str);
		printf("%s", str);
		str = get_next_line(fd3);
		free(str);
	}
	close(fd);
	return (0);
}
