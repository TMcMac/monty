#include "monty.h"

/**
 * 
 * 
 **/
FILE *file_check(const char *filename)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL || access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	return (fp);
}

/**
 * 
 * 
 **/
void clean_up(FILE **fp, stack_t **stack, char **buffer)
{
    stack_t *mover;

    if (fp != NULL)
        close(fp);
    if (*buffer != NULL)
        free(*buffer);
    if (buffer != NULL)
        free(buffer);
    if (*stack != NULL)
    {
        mover = *stack;
        while (*stack != NULL)
        {
            *stack = *stack->next;
            free(mover;
            mover = *stack;
        }
        free(stack);
    }
}