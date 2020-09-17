#include "monty.h"
#include <ctype.h>

glbnfo *info = NULL;

/**
 *
 *
 *
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_size;
	unsigned int line_count = 0;
	int i = 0;
	char *cmd_toks;
	char *command[50];
	char delimit[] = " \t\n";
	const char *filename;
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	fp = fopen(filename, "r");
	file_check(fp, filename);
	info = malloc(sizeof(glbnfo));
	if (info == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	info->fp = &fp;
	info->buffer = &line_buf;
	line_size = getline(&line_buf, &line_buf_size, fp);
	printf("Made it past getline 1\n");
	while (line_size >= 0)
	{
		/* Incremeant our line count */
		line_count += 1;
		/* First we tokenize our line from getline */
		cmd_toks = strtok(line_buf, delimit);
		printf("Made it into while loop for getline and past strtok1\n");
		/* Next we will take anything not a space and put it in an array of tokens*/
		while (cmd_toks != NULL)
		{
			command[i] = cmd_toks;
			printf("In the inner while loop for cmd_toks\n");
			cmd_toks = strtok(NULL, delimit);
			i++;
		}
		printf("Past the cmd_toks loop, sending to cmd_comp\n");
		printf("Arg0: %s$\nArg1: %s$\n", command[0], command[1]);
		cmd_comp(command, &stack, line_count);
		printf("Returned from cmd comp next line\n");
	    line_size = getline(&line_buf, &line_buf_size, fp);
	    i = 0;
	}
	fclose(fp);
	return (0);
}
