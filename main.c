#include "monty.h"

extern int line_count;
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
	size_t line_size;
	line_count = 0;

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
	while (line_size != 0)
	{
		/* Incremeant our line count */
		line_count++;

		/* Show the line details */
    	printf("line[%03d]: buf size=%06zu, contents: %s", line_count, line_buf_size, line_buf);

    	/* Get the next line */
    	line_size = getline(&line_buf, &line_buf_size, fp);
	}

	fclose(fp);
	return (0);
}
