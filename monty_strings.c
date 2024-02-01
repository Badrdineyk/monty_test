#include "monty.h"

/**
 * stack_pchar - prints the char at the top of the stack.
 * @stack: A pointer to the top mode node.
 * @ln: current working line number.
 */
void stack_pchar(stack_t **stack, unsigned int ln)
{
	int code_ascii;

	if (stack == NULL || *stack == NULL)
		error_str_handler(11, ln);

	code_ascii = (*stack)->n;
	if (code_ascii < 0 || code_ascii > 127)
		error_str_handler(10, ln);
	printf("%c\n", code_ascii);
}

/**
 * stack_pstr - prints the string starting at the top of the stack
 * @stack: A pointer to the top mode node.
 * @line_number: current working line number.
 */
void stack_pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int code_ascii;
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	ptr = *stack;
	while (ptr != NULL)
	{
		code_ascii = ptr->n;
		if (code_ascii <= 0 || code_ascii > 127)
			break;
		printf("%c", code_ascii);
		ptr = ptr->next;
	}
	printf("\n");
}

/**
 * stack_rotl - rotates the stack to the top.
 * @stack: A pointer to the top mode node.
 * @line_number: current working line number.
 */
void stack_rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	ptr = *stack;
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = *stack;
	(*stack)->prev = ptr;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * stack_rotr -  rotates the stack to the bottom.
 * @stack: A pointer to the top mode node.
 * @line_number: current working line number.
 */
void stack_rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	ptr = *stack;

	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = *stack;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	(*stack)->prev = ptr;
	(*stack) = ptr;
}
