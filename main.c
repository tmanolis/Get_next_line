#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("texte.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf(">>> line : |%s| <<<\n", line);
		free(line);
	}
	printf(">>> line : |%s| <<<\n", line);
	close (fd);
	return (0);
}