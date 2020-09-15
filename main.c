#include "monty.h"

int line_count = 0;
/**
 *
 *
 *
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_size;
	stack_t *head;
	char *command;

	/* First Check, only run program + file path */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
    }

	/* Second check, open the file*/
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* Get the first line from input */
	line_size = getline(&line_buf, &line_buf_size, fp);

	/* enter the loop of parsing and getting lines from fp */
	while (line_size >= 0)
	{
		/* Incremeant our line count */
		line_count++;

		/* Show the line details */
		command = strtok(line_buf, " ");
		printf("%s\n", command);

		/* Get the next line */
	    line_size = getline(&line_buf, &line_buf_size, fp);
	}

	fclose(fp);
	return (0);
}


/**
*
*
*
*


char *trim(char *line_buf)
{
	int i = 0, j = 0;
	char new_string[];

	while (line_buf[i] == ' ' || line_buf[i] =='\t')
		i++;
	for(;linebuff[i] != '\0'; i++, j++)
		new_string[j] = line_buf[i]; 
}
*/