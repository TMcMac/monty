#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
    stack_t *top = (*stack);

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n", line_num);
        clean_up(info->fp, stack, info->buffer);
        exit(EXIT_FAILURE);
    }
    new_node->next = NULL;
    new_node->n = info->num;
    new_node->prev = top;
    top->next = new_node;
    (*stack) = new_node;

}
void _pall(stack_t **stack, unsigned int line_number)
{
    stack_t *mover = (*stack);
    while (mover != NULL)
    {
        printf("%d\n", mover->n);
        mover = mover->prev;
    }
}
void _pint(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
