#include "monty.h"
/**
 *FREE_STACK - frees all elements of stack
 *@stack: a pointer to the head node
 */

void FREE_STACK(stack_t **stack)
{
	stack_t *node = NULL;

	if (!stack || !*stack)
		return;
	while (*stack)
	{
		node = *stack;
		*stack = (*stack)->next;
		free(node);
	}
	*stack = NULL;
}

/**
 *sub_err- handles error for op_sub
 *@stack: a ptr to head node
 *@line_number: a line wear error occured
 */
void sub_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	FREE_STACK(stack);
	exit(EXIT_FAILURE);
}
