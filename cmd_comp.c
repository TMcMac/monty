#include "monty.h"

/**
 * opcode_comp - compare arg to avaiable op codes
 * @line_num: line_number counter
 * @cmd: parsed getline for opcode and args
 * Return: Nothing
 */

void cmd_comp(char *cmd[], stack_t **stack, unsigned int line_num)
{
	int i = 0, j = 0;

	instruction_t opcodes[] = {
		{"pall", _pall}, {"push", _push}, {NULL, NULL}
	};  /* To be added {"pint", _pint},
		{"pop", _pop}, {"add", _add}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"nop", _nop}, {"mod", _mod},
		{"swap", _swap}, */

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, cmd[0]) == 0)
		{
			if (strcmp(opcodes[i].opcode, "push") == 0)
            {
                /* I am going to need to check for spaces and fail conditions down the line */
                while (cmd[1][j])
                {
                    if (isdigit(cmd[1][j]))
                        continue;
                    else
                    {
                        fprintf(stderr, "L%u: usage: push integer\n", line_num);
                        clean_up(info->fp, stack, info->buffer);
                        exit(EXIT_FAILURE);
                    }
                } 
                info->num = atoi(cmd[1]);
                _push(stack, line_num);
            }
		}
	}
    if (opcodes[i].opcode == NULL)
    {
	    fprintf(stderr, "L%u: unknown instruction %s\n", line_num, cmd[0]);
	    clean_up(info->fp, stack, info->buffer);
    }
}
