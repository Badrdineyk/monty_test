#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

stack_t *node_creator(int data);
void stack_free(void);
void stack_pall(stack_t **, unsigned int);
void stack_push(stack_t **, unsigned int);
void queue_push(stack_t **, unsigned int);

void func_caller(op_func, char *, char *, int, int);

void stack_pint(stack_t **, unsigned int);
void stack_pop(stack_t **, unsigned int);
void stack_nop(stack_t **, unsigned int);
void stack_swap(stack_t **, unsigned int);

void stack_add(stack_t **, unsigned int);
void stack_sub(stack_t **, unsigned int);
void stack_div(stack_t **, unsigned int);
void stack_mul(stack_t **, unsigned int);
void stack_mod(stack_t **, unsigned int);

void f_open(char *name_f);
int tokenize_line(char *line_buff, int ln, int format);
void f_read(FILE *);
void fun_finder(char *, char *, int, int);

void stack_pchar(stack_t **, unsigned int);
void stack_pstr(stack_t **, unsigned int);
void stack_rotl(stack_t **, unsigned int);

void errors_handler(int err_num, ...);
void errors_handler_more(int err_num, ...);
void error_str_handler(int err_num, ...);
void stack_rotr(stack_t **, unsigned int);

#endif /* MONTY_H */
