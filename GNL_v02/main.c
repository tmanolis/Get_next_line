#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("test.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf(">>> line : |%s| <<<", line);
		free(line);
	}
	line = get_next_line(fd);
	printf(">>> line : |%s| <<<\n", line);
	free(line);
	line = get_next_line(fd);
	printf(">>> line : |%s| <<<\n", line);
	free(line);
	line = get_next_line(fd);
	printf(">>> line : |%s| <<<\n", line);
	free(line);
	line = get_next_line(fd);
	printf(">>> line : |%s| <<<\n", line);
	free(line);
	line = get_next_line(fd);
	printf(">>> line : |%s| <<<\n", line);
	free(line);
	line = get_next_line(fd);
	printf(">>> line : |%s| <<<\n", line);
	free(line);
	
	close (fd);
	return (0);
}
