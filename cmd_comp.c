#include "monty.h"

/**
 * 
 * 
 **/



#include "monty.h"

/**
 * opcode_comp - compare arg to avaiable op codes
 * @line_numb: line_number counter
 * @cmd: parsed getline for opcode and args
 * Return: Nothing
 */

void cmd_comp(char *cmd, int line_num)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"pall", _pall}, {"push", _push}, {"pint", _pint},
		{"pop", _pop}, {"add", _add}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"nop", _nop}, {"mod", _mod},
		{"swap", _swap}, {NULL, NULL}
	};
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, arg) == 0)
		{
			if (strcmp(opcodes[i].opcode, "push") == 0)
			{
				status = getpushint(arg, line_number);
			}
			else
				status = check_exe(stack, line_number, arg);
			if (status == 0)
			{
				opcodes[i].f(stack, line_number);
				return (0);
			}
			/*
			 *else
			 *	{
			 *	exit(0);
			 *	return (-1);
			 *	}
			 */
		}
	}
	/*
	 *fprintf(stderr, "L%u: unknown instruction %s\n", line_number, arg);
	 */
}
