#include "monty.h"

void stack_push(stack_t **node, __attribute__((unused)) unsigned int line_num);
void stack_pall(stack_t **stack, unsigned int ln);
void stack_pop(stack_t **stack, unsigned int ln);

/**
 * stack_push - pushes a node to the stack.
 * @node: A pointer a new node
 * @line_num: current working line number.
 */
void stack_push(stack_t **node, __attribute__((unused)) unsigned int line_num)
{
	stack_t *ptr;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	ptr = head;
	head = *node;
	head->next = ptr;
	ptr->prev = head;
}

/**
 * stack_pall - prints all the values on the stack.
 * @stack: A Pointer to top node of the stack.
 * @ln: current working line number.
 */
void stack_pall(stack_t **stack, unsigned int ln)
{
	stack_t *ptr;
	(void)ln;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * stack_pop - removes the top element of the stack.
 * @stack: A Pointer to top node of the stack.
 * @ln: current working line number.
 */
void stack_pop(stack_t **stack, unsigned int ln)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
		errors_handler_more(7, ln);
	ptr = *stack;
	*stack = ptr->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(ptr);
}
