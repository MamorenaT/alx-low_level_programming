#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
* create_buffer - The number of bytes in a buffer.
* @file: the name of a file.
* Return: Input a name for the file.
*/

char *create_buffer(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
	dprintf(STDERR_FILENO,
	"Error: Can't write to %s\n", file);
	exit(99);
	}

	return (buf);
}

/**
* close_file - Shut down the descriptors.
* @ef: The descriptors in the file.
*/

void close_file(int ef)
{
	int b;

	b = close(ef);

	if (b == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close ef %d\n", ef);
	exit(100);
	}
}

/**
* main - The program checks the code for students.
* @argc: The amount of arguments
* @argv: The arguments vector
* Return: Always print 0
* Description: If the amount of argument is incorrect - exit code 97.
* If file_from does not exist or cant read - exit code 98.
* If file_to cannot be generated or printed to - exit code 99.
* If file_to or file_from cant be exited - exit code 100.
*/

int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
	if (from == -1 || r == -1)
	{
	dprintf(STDERR_FILENO,
	"Error: Can't read from file %s\n", argv[1]);
	free(buffer);
	exit(98);
	}

	w = write(to, buffer, r);
	if (to == -1 || w == -1)
	{
	dprintf(STDERR_FILENO,
	"Error: Can't write to %s\n", argv[2]);
	free(buffer);
	exit(99);
	}

	r = read(from, buffer, 1024);
	to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
