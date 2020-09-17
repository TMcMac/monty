#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
    stack_t *oldtop;
    stack_t *new_node = malloc(sizeof(stack_t));
    (void) line_number;

    printf("We've made it to basic funcs!!\n");
    if (new_node == NULL)
    {
      printf("New Node is null??\n");
        fprintf(stderr, "Error: malloc failed\n");
        clean_up(info->fp, stack, info->buffer);
        exit(EXIT_FAILURE);
    }
    printf("Assigning things to new node\n");
    new_node->next = NULL;
    new_node->n = info->num;
    printf("Next and N are assigned\n");
    if (*stack == NULL)
      {
	new_node->prev = NULL;
	printf("prev is assigned null\n");
      }
    else
    {
      oldtop = *stack;
      new_node->prev = oldtop;
      oldtop->next = new_node;
    }
    printf("assigning deref stack to new node\n");
    *stack = new_node;
    printf("Umm where is the problem?\n");
    return;
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
    return;
}
/*
void _pint(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
*/
