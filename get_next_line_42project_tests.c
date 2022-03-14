// for testing
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "get_next_line.h"

//if -D is absent while testing
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		return (42);
		printf("Il faut plus d'un argument\n");
	}
	static size_t	line_number = 0;
	char	*current_line = malloc(BUFFER_SIZE);
	if (!current_line)
		return (42);

	if (strstr(argv[1], ".txt"))
	{
		// opening the file and printing line by line
		int 			fd = open(argv[1], O_RDONLY);
		if (fd)
			printf("========== File Opened succesfully ==========\n\n");
		while ((current_line = get_next_line(fd)))
		{
			printf("Line number %ld: %s\n", line_number, current_line);
			line_number++;
		}
		close(fd);
	}
	return (0);
}
