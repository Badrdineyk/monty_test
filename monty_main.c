#include "monty.h"

int main(int argc, char *argv[]);
stack_t *node_creator(int data);
void stack_free(void);
void queue_push(stack_t **node, __attribute__((unused)) unsigned int line_num);

stack_t *head = NULL;

/**
 * main - the entry point for Monty Interp
 * @argc: The number of arguments.
 * @argv: A pointer to an array of arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_open(argv[1]);
	stack_free();
	return (0);
}

/**
 * node_creator - creates a new node.
 * @data: An integer.
 *
 * Return: The address of the new node.
 * or NULL.
 */
stack_t *node_creator(int data)
{
	stack_t *new_n;

	new_n = malloc(sizeof(stack_t));
	if (new_n == NULL)
		errors_handler(4);
	new_n->next = NULL;
	new_n->prev = NULL;
	new_n->n = data;
	return (new_n);
}

/**
 * stack_free - Frees the stack.
 */
void stack_free(void)
{
	stack_t *ptr;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}

/**
 * queue_push - Pushs a node to the queue
 * @node: A Pointer to the new node.
 * @line_num: line number of the opcode.
 */
void queue_push(stack_t **node, __attribute__((unused)) unsigned int line_num)
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
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = *node;
	(*node)->prev = ptr;
}
