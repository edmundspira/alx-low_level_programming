#include "main.h"

/**
 * read_textfile - Prints text file to the POSIX standard output
 * @filename: The source file
 * @letters: Number of letters to reads and prints
 *
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = open(filename, O_RDONLY);
	ssize_t b;
	char *buf = malloc(sizeof(char) * letters + 1);

	if (fd == -1)
		return (0);
	if (!buf | !filename)
		return (0);
	b = read(fd, buf, letters);

	if (b == -1)
		return (0);
	buf[b] = '\0';
	b = write(STDOUT_FILENO, buf, b);

	if (b == -1)
		return (0);

	close(fd);
	free(buf);
	return (b);
}
