#include "monty.h"
#include <ctype.h>

glbnfo *info;

void parse(FILE *fp);

/**
 *
 *
 *
 */
int main(int argc, char **argv)
{
	const char *filename;
	FILE *fp;

	/* First Check, only run program + file path */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	printf("First file check?\n");
	filename = argv[1];
	/* Second check, open the file*/
	fp = fopen(filename, "r");
	printf("File pointer opened\n");
	if (fp == NULL || access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	printf("made it past file checks\n");
	/*	info->stack = NULL; */
	parse(fp);

	fclose(fp);
	return (0);
}

/**
 * 
 * 
 * 
 */
void parse(FILE *fp)
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_size;
	unsigned int line_count = 0;
	int i = 0;
	char *cmd_toks;
	char *command[50];
	char delimit[] = " \t\r\n\v\f";

	printf("In parse\n");
	/* Get the first line from input */
	line_size = getline(&line_buf, &line_buf_size, fp);
	/* enter the loop of parsing and getting lines from fp */
	while (line_size >= 0)
	{
		/* Incremeant our line count */
		line_count += 1;
		/* First we tokenize our line from getline */
		cmd_toks = strtok(line_buf, delimit);
		printf("%s\n", cmd_toks);
		/* Next we will take anything not a space and put it in an array of tokens*/
		while (cmd_toks != NULL)
		{
		    if (strcmp(cmd_toks, " ") != 0)
		    {
			command[i] = cmd_toks;
			cmd_toks = strtok(NULL, delimit);
			i++;
		    }
		}
		/* Reset I for future use*/
		i = 0;
        /* This is where we will need to call a function pointer struct and see what operation we need to do*/
		/* I think we'll always be sending a head pointer and line number, and getting back the head pointer*/
			/*cmd_comp(command[0], line_count);*/
		/* Get the next line */
	    line_size = getline(&line_buf, &line_buf_size, fp);
	}
}
