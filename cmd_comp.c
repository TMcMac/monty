#include "monty.h"

/**
 * opcode_comp - compare arg to avaiable op codes
 * @line_num: line_number counter
 * @cmd: parsed getline for opcode and args
 * Return: Nothing
 */

void cmd_comp(char *cmd[], stack_t **stack, unsigned int line_num)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pall", _pall}, {"push", _push}, {NULL, NULL}
	};  /* To be added {"pint", _pint},
		{"pop", _pop}, {"add", _add}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"nop", _nop}, {"mod", _mod},
		{"swap", _swap}, */
	printf("In cmd_comp after decs\n");
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
	    printf("in the for loop to check op-codes\n");
	    if (strcmp(opcodes[i].opcode, cmd[0]) == 0)
		{
		    printf("We have a match on %s\n", cmd[0]);
		    printf("Next is %s\n", cmd[1]);
			if (strcmp(opcodes[i].opcode, "push") == 0)
			    {
			        printf("The match is for push\n");
			        /* I am going to need to check for spaces and fail conditions down the line */
			        if (isdigit(cmd[1][0]) != 0)
			        {
				        printf("Inside the atoi if\n");
				        info->num = atoi(cmd[1]);
				        printf("After info->num assignment of %d\n", info->num);
				        opcodes[i].f(stack, line_num);
				        printf("We make it back to cmd_comp\n");
				        return;
			        }
			        else
			        {
				        fprintf(stderr, "L%u: usage: push integer\n", line_num);
				        clean_up(info->fp, stack, info->buffer);
				        exit(EXIT_FAILURE);
			        }
			    }
			else
            {
			    opcodes[i].f(stack, line_num);
                return;
            }
		}
	}
	if (opcodes[i].opcode == NULL)
	{
	    fprintf(stderr, "L%u: unknown instruction %s\n", line_num, cmd[0]);
	    clean_up(info->fp, stack, info->buffer);
	}
}
