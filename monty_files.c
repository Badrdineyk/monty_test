#include "monty.h"

/**
 * f_open - Opens the file.
 * @name_f: Path of the file.
 */
void f_open(char *name_f)
{
	FILE *disc_file = fopen(name_f, "r");

	if (name_f == NULL || disc_file == NULL)
		errors_handler(2, name_f);

	f_read(disc_file);
	fclose(disc_file);
}

/**
 * f_read - Reads the file.
 * @disc_file: File discriptor
 */
void f_read(FILE *disc_file)
{
	int ln, format = 0;
	char *line_buff = NULL;
	size_t length = 0;

	for (ln = 1; getline(&line_buff, &length, disc_file) != -1; ln++)
	{
		format = tokenize_line(line_buff, ln, format);
	}
	free(line_buff);
}

/**
 * tokenize_line - Tokenizes the lines
 * @line_buff: file's line
 * @ln: the number of the line
 * @format: int to store the format
 *
 * Return: Returns 1 if queue, 0 if stack.
 */
int tokenize_line(char *line_buff, int ln, int format)
{
	char *curr_val, *opcode;
	const char *sep = "\n ";

	if (line_buff == NULL)
		errors_handler(4);

	opcode = strtok(line_buff, sep);
	if (opcode == NULL)
		return (format);
	curr_val = strtok(NULL, sep);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	fun_finder(opcode, curr_val, ln, format);
	return (format);
}

/**
 * fun_finder - Finds the functions
 * @opcode: opcode value
 * @curr_val: Current value of opcode
 * @format: int to store the format
 * @ln: the number of the line
 */
void fun_finder(char *opcode, char *curr_val, int ln, int format)
{
	int flag;
	int index;

	instruction_t list_funcs[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"nop", stack_nop},
		{"swap", stack_swap},
		{"add", stack_add},
		{"sub", stack_sub},
		{"div", stack_div},
		{"mul", stack_mul},
		{"mod", stack_mod},
		{"pchar", stack_pchar},
		{"pstr", stack_pstr},
		{"rotl", stack_rotl},
		{"rotr", stack_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, index = 0; list_funcs[index].opcode != NULL; index++)
	{
		if (strcmp(opcode, list_funcs[index].opcode) == 0)
		{
			func_caller(list_funcs[index].f, opcode, curr_val, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors_handler(3, ln, opcode);
}

/**
 * func_caller - Calls the functions.
 * @ptr_func: A Pointer to the function to be called.
 * @str_op: A pointer to the string of the opcode.
 * @str_val: A pointer string to the numeric value.
 * @ln: the number of the line
 * @format: int to store the format
 */
void func_caller(op_func ptr_func, char *str_op, char *str_val, int ln, int format)
{
	stack_t *new_node;
	int index;
	int flag;

	flag = 1;
	if (strcmp(str_op, "push") == 0)
	{
		if (str_val != NULL && str_val[0] == '-')
		{
			str_val = str_val + 1;
			flag = -1;
		}
		if (str_val == NULL)
			errors_handler(5, ln);
		for (index = 0; str_val[index] != '\0'; index++)
		{
			if (isdigit(str_val[index]) == 0)
				errors_handler(5, ln);
		}
		new_node = node_creator(atoi(str_val) * flag);
		if (format == 0)
			ptr_func(&new_node, ln);
		if (format == 1)
			queue_push(&new_node, ln);
	}
	else
		ptr_func(&head, ln);
}
