#include "monty.h"

/**
 * stack_add - adds the top two elements of a stack_t linked list.
 * @stack: A pointer to the top mode node.
 * @ln: current working line number.
 */
void stack_add(stack_t **stack, unsigned int ln)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_handler_more(8, ln, "add");
	(*stack) = (*stack)->next;
	res = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = res;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * stack_sub - subtracts the top element of the stack
 * @stack: A pointer to the top mode node.
 * @ln: current working line number.
 */
void stack_sub(stack_t **stack, unsigned int ln)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_handler_more(8, ln, "sub");
	(*stack) = (*stack)->next;
	res = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = res;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * stack_div - divides the second top element of the stack
 * @stack: A pointer to the top mode node.
 * @ln: current working line number.
 */
void stack_div(stack_t **stack, unsigned int ln)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_handler_more(8, ln, "div");
	if ((*stack)->n == 0)
		errors_handler_more(9, ln);
	(*stack) = (*stack)->next;
	res = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = res;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * stack_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: A pointer to the top mode node.
 * @ln:current working line number.
 */
void stack_mul(stack_t **stack, unsigned int ln)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_handler_more(8, ln, "mul");
	(*stack) = (*stack)->next;
	res = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = res;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * stack_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: A pointer to the top mode node.
 * @ln: current working line number.
 */
void stack_mod(stack_t **stack, unsigned int ln)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_handler_more(8, ln, "mod");
	if ((*stack)->n == 0)
		errors_handler_more(9, ln);
	(*stack) = (*stack)->next;
	res = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = res;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
