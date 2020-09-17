#include "monty.h"

/**
 * opcode_comp - compare arg to avaiable op codes
 * @line_num: line_number counter
 * @cmd: parsed getline for opcode and args
 * Return: Nothing
 */

void cmd_comp(char *cmd[], unsigned int line_num)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"pall", _pall}, {"push", _push}, {"pint", _pint},
		{"pop", _pop}, {NULL, NULL}
	};  /* To be added {"add", _add}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"nop", _nop}, {"mod", _mod},
		{"swap", _swap}, */
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, cmd[0]) == 0)
		{
			printf("%s matched an opcode!!!", cmd[0]);
		}
	}
    if (opcodes[i].opcode == NULL)
    {
	    fprintf(stderr, "L%u: unknown instruction %s\n", line_num, cmd[0]);
        clean_up(info->fp, info->stack, info->buffer);
    }
}
