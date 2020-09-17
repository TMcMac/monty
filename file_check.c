#include "monty.h"

/**
 * 
 * 
 **/
void file_check(FILE *fp, const char *filename)
{
	if (fp == NULL || access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * 
 * 
 **/
void clean_up(FILE **fp, stack_t **stack, char **buffer)
{
    stack_t *mover;

    if ((*fp) != NULL)
      fclose((*fp));
    if (*buffer != NULL)
        free(*buffer);
    if (*stack != NULL)
    {
        mover = *stack;
        while (*stack != NULL)
        {
	  (*stack) = (*stack)->prev;
          free(mover);
          mover = *stack;
	}
    }
}
