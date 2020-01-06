#include "monty.h"

/**
 * main - the entry point for Monty Interpreter
 *
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */

char *opCodeVal = NULL;

int main(int argc, char **argv)
{
	FILE *file_fd = NULL;
	stack_t *Stack = NULL;
	int code_return = 0;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;
	char *opCode = NULL;

	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file_fd = fopen(argv[1], "r");
	if (file_fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, file_fd)) != -1)
	{
		line_number++;
		opCode = strtok(line, DELIMITERS);
		if (opCode == NULL || strncmp(opCode, "#", 1) == 0)
			continue;
		opCodeVal = strtok(NULL, DELIMITERS);
		opCode_Functions(&Stack, opCode, line_number);
	}
	fclose(file_fd);
	return (code_return);
}
