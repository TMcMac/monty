#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
    stack_t *oldtop;
    stack_t *new_node = malloc(sizeof(stack_t));
    (void) line_number;

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        clean_up(info->fp, stack, info->buffer);
        exit(EXIT_FAILURE);
    }
    new_node->next = NULL;
    new_node->n = info->num;
    if (*stack == NULL)
      new_node->prev = NULL;
    else
    {
      oldtop = *stack;
      new_node->prev = oldtop;
      oldtop->next = new_node;
    }
    *stack = new_node;

}
void _pall(stack_t **stack, unsigned int line_number)
{
    stack_t *mover = *stack;
    (void) line_number;

    while (mover != NULL)
    {
        printf("%d\n", mover->n);
        mover = mover->prev;
    }
}
/*
void _pint(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
*/
