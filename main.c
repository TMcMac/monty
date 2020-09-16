#include "monty.h"
#include <ctype.h>

/**
 *
 *
 *
 */
int main(int argc, char **argv)
{
	const char *filename;
	
	/* First Check, only run program + file path */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
    }
	filename = argv[1];
	/* Second check, open the file*/
	info.fp = fopen(filename, "r");
	if (info.fp == NULL || access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	info.head = NULL;
	parse(info.fp);

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

	/* Get the first line from input */
	line_size = getline(&line_buf, &line_buf_size, fp);
	/* enter the loop of parsing and getting lines from fp */
	while (line_size >= 0)
	{
		/* Incremeant our line count */
		line_count += 1;
		/* First we tokenize our line from getline */
		cmd_toks = strtok(line_buf, delimit);
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
		
		//cmd_comp(command[0], line_count);
		/* Get the next line */
	    line_size = getline(&line_buf, &line_buf_size, fp);
	}
}
