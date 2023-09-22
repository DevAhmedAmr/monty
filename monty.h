#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define UNUSED(x) (void)(x)

/*char **op_code_arr;*/

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 *
 */
typedef struct stack_t
{
	int n;
	struct stack_t *prev;
	struct stack_t *next;
} stack_t;
size_t print_stack_t(const stack_t *h);
size_t stack_t_len(const stack_t *h);
stack_t *add_at_beginning_stack_t(stack_t **head, const int n);
stack_t *add_stack_t_end(stack_t **head, const int n);
void free_stack_t(stack_t *head);
stack_t *get_stack_t_at_index(stack_t *head, unsigned int index);
int sum_stack_t(stack_t *head);
stack_t *insert_stack_t_at_index(stack_t **h, unsigned int idx, int n);
stack_t *add_head(stack_t **head, int n);
int delete_node_stack_t_at_index(stack_t **head, unsigned int index);
int double_arr_len(char **arr);
void pint(stack_t **h, unsigned int line_number);
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 *
 *  for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct aircraft_s
{
	char *input;
	char **input_splitted;
	FILE *file;
	stack_t *stack;
	int error_number;
} aircraft_s;

aircraft_s vars_aircraft;
/*extern aircraft_s vars_aircraft;*/
void unknown_instruction_err(int line_number, char *optcode);
void push(stack_t **stack, unsigned int line_number);
int errors_handling(stack_t **stack, unsigned int line_number);
void pall(stack_t **input, unsigned int line_number);
int free_grid(char **arr);
char **string_toList(char *input);
void print_grid(char **input_toList);
/*extern char **op_code_arr;*/
void compare_fun(char **input_splitted, const int line_number, stack_t **stack);
int double_arr_len(char **arr);
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **h, unsigned int line_number);
void swap(stack_t **h, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
#define malloc_failur(allocated_var)                   \
	{                                                  \
		if (allocated_var == NULL)                     \
		{                                              \
			fprintf(stdout, "Error: malloc failed\n"); \
			exit(EXIT_FAILURE);                        \
		}                                              \
	}
#endif
