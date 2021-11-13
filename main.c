#include "get_next_line.h"

int		main()
{
	int		fd;
	char	*str;
	fd = open("myfile.txt", O_RDONLY);
	str = get_next_line(fd);
	free(str);
	while (str != 0)
	{
		printf("%s", str);
		str = get_next_line(fd);
		free(str);
	}
	close(fd);
	return (0);
}
