#include "monty.h"

int short_stackError(unsigned int line_num, char *op);
int _div_error(unsigned int line_num);
int _pop_error(unsigned int line_num);
int _pchar_error(unsigned int line_num, char *message);
int _div_error(unsigned int line_num);


/**
 * _pop_error - Prints pop error messages for empty stacks.
 * @line_num: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int _pop_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
	return (EXIT_FAILURE);
}

/**
 * _pint_error - function Prints pint error messages for empty stacks.
 * @line_num: the Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int _pint_error(unsigned int line_num)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
	return (EXIT_FAILURE);
}

/**
 * _short_stack_error - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @line_num: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int short_stackError(unsigned int line_num, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_num, op);
	return (EXIT_FAILURE);
}
/**
 * _pchar_error - it  Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_num: the Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */

int _pchar_error(unsigned int line_num, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_num, message);
	return (EXIT_FAILURE);
}

/**
 * _div_error - it Prints division error messages for division by 0.
 * @line_num: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int _div_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: division by zero\n", line_num);
	return (EXIT_FAILURE);
}
