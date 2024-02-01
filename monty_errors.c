#include "monty.h"

/**
 * errors_handler - handlers the errors.
 * @err_num: The number of the error
 */
void errors_handler(int err_num, ...)
{
	int line_num;
	va_list list_args;
	char *op;

	va_start(list_args, err_num);
	switch (err_num)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(list_args, char *));
			break;
		case 3:
			line_num = va_arg(list_args, int);
			op = va_arg(list_args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(list_args, int));
			break;
		default:
			break;
	}
	stack_free();
	exit(EXIT_FAILURE);
}

/**
 * errors_handler_more - handles more errors.
 * @err_num: The number of the error
 */
void errors_handler_more(int err_num, ...)
{
	int line_num;
	va_list list_args;
	char *op;

	va_start(list_args, err_num);
	switch (err_num)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(list_args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(list_args, int));
			break;
		case 8:
			line_num = va_arg(list_args, unsigned int);
			op = va_arg(list_args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(list_args, unsigned int));
			break;
		default:
			break;
	}
	stack_free();
	exit(EXIT_FAILURE);
}

/**
 * error_str_handler - Prints the errors
 * @err_num: The number of the error
 */
void error_str_handler(int err_num, ...)
{
	int line_num;
	va_list list_args;

	va_start(list_args, err_num);
	line_num = va_arg(list_args, int);
	switch (err_num)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	stack_free();
	exit(EXIT_FAILURE);
}
