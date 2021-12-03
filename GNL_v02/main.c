#include "get_next_line.h"
#include <stdio.h>

void f(void)
{
    system("leaks a.out");
}

int main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf(">>> line : |%s| <<<\n", line);
		free(line);
	}
	line = get_next_line(fd);
	printf(">>> line : |%s| <<<\n", line);
	free(line);
	// atexit(f);
	close (fd);
	return (0);
}
