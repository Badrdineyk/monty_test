#include "monty.h"

/**
 * stack_nop - Does absolutely nothing.
 * @stack: A pointer to the top mode node.
 * @ln: current working line number.
 */
void stack_nop(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
}

/**
 * stack_swap - swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node.
 * @ln: current working line number.
 */
void stack_swap(stack_t **stack, unsigned int ln)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_handler_more(8, ln, "swap");
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = *stack;
	ptr->next = *stack;
	(*stack)->prev = ptr;
	ptr->prev = NULL;
	*stack = ptr;
}

/**
 * stack_pint - prints the value at the top of the stack
 * @stack: A Pointer to top node of the stack.
 * @ln: current working line number.
 */
void stack_pint(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		errors_handler_more(6, ln);
	printf("%d\n", (*stack)->n);
}
