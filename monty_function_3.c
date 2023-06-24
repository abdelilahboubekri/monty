#include "monty.h"

void _nop(stack_t **stack, unsigned int line_num);
void _pchar(stack_t **stack, unsigned int line_num);
void _pstr(stack_t **stack, unsigned int line_num);
void _rotl(stack_t **stack, unsigned int line_num);
void _rotr(stack_t **stack, unsigned int line_num);
void _stack(stack_t **stack, unsigned int line_num);
void _queue(stack_t **stack, unsigned int line_num);

/**
 * _nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The line number of a Monty bytecodes file.
 */
void _nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * _pchar - it Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: the line number of a Monty bytecodes file.
 */
void _pchar(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(_pchar_error(line_num, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(_pchar_error(line_num,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * _pstr - it p rints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: the line number of a Monty bytecodes file.
 */
void _pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_num;
}

/**
 * _rotl - it Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The number of a Monty bytecodes file.
 */
void _rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_num;
}

/**
 * _rotr - it rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The  line number of a Monty bytecodes file.
 */
void _rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_num;
}

/**
 * _stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The line number of a Monty bytecodes file.
 */
void _stack(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = STACK;
	(void)line_num;
}

/**
 * _queue - it converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: the line number of a Monty bytecodes file.
 */
void _queue(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = QUEUE;
	(void)line_num;
}
