#include "monty.h"

void get_stream(char *filename)
{
	int fd;
	fd = open(filename, O_RDONLY);

	if (fd == -1)
		getting_stream_failed(filename);

	arguments->stream = fdopen(fd, "r");

	if (arguments->stream == NULL)
	{
		close(fd);
		getting_stream_failed(filename);
	}
}
