#include "monty.h"

void _add(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void _mul(stack_t **stack, unsigned int line_num);
void _mod(stack_t **stack, unsigned int line_num);

/**
 * add - function to adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */

void _add(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(_short_stack_error(line_num, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_num);
}

/**
 * _sub - it  Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void _sub(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(_short_stack_error(line_num, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	_pop(stack, line_num);
}

/**
 * _div - it divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: the  line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void _div(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(_short_stack_error(line_num, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(_div_error(line_num));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	_pop(stack, line_num);
}

/**
 * _mul -it multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: the  line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void _mul(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(_short_stack_error(line_num, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	_pop(stack, line_num);
}

/**
 * _mod - it xcmputes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: the pointer to the top mode node of a stack_t linked list.
 * @line_num: the line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void _mod(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(_short_stack_error(line_num, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(_div_error(line_num));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	_pop(stack, line_num);
}
