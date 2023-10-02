
#include "main.h"
#include <stdio.h>
/**
 * error_file - to check a file if its opened and handle errors
 * @file_from: a file to copy from and check it.
 * @file_to: destination file to copy.
 * @argv: argument vector.
 * Return: 0
 */

void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
	}
}
/**
 * main - copy the contents.
 * @argv: argument vector.
 * @argc: argument vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from;
	int file_to;
	int err_close;
	ssize_t nc, r;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT | O_APPEND, 0664);
	error_file(file_from, file_to, argv);
	nc = 1024;
	while (nc == 1024)
	{
		nc = read(file_from, buf, 1024);
		if (nc == -1)
			error_file(-1, 0, argv);
		r = write(file_to, buf, nc);
		if (r == -1)
			error_file(0, -1, argv);
	}
	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
