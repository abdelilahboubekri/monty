#include "monty.h"
#include "monty.h"

/**
 * _div - fia ffnction div two number
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _div(stack_t **stack, unsigned int line_num)
{
	stack_t *curerent = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	curerent = *stack;
	div = curerent->next->n / curerent->n;
	curerent->next->n = div;
	_pop(stack, line_num);

}


/**
 * _mod - computes the rest of the division of the second top element
 * @stack: Stack.
 * @line_number: Number of line
 */
void _mod(stack_t **stack, unsigned int line_num)
{
	stack_t *curerent = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	curerent = *stack;
	div = curerent->next->n % curerent->n;
	curerent->next->n = div;
	_pop(stack, line_num);
}
/**
 * _mul -  to multiplies the second top with the top element.
 * @stack: Stack.
 * @line_num: Number of line
 */
 
void _mul(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int mul = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;

	mul = current->next->n * current->n;
	_pop(stack, line_num);
	current->next->n = mul;
}
/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: Stack.
 * @line_number: Number of line
 */
void _pchar(stack_t **stack, unsigned int line_num)
{
	int num = 0;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	putchar(num);
	putchar(10);
}

/**
 * _pstr - funton to  Print a string.
 * @stack: stack
 * @line_num: Number of line
 */
void _pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;
	(void)line_num;

	while (current && current->n)
	{
		if (current->n < 32 || current->n > 127)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	putchar(10);
}

/**
 * _swap -  function to swaps the top two elements of the stack.
 * @stack: Stack
 * @line_number: Number of the line
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;
	int temp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
/**
 * _pop - function to  removes the top element of the stack.
 * @stack: Stack list
 * @line_num: Number of the line
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}
/**
 * _add - to function add two integer
 * @stack: Stack list
 * @line_num: Number of the line
 */
void _add(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	_pop(stack, line_num);
}

/**
 * _sub - function to subtracts the top element of the stack from the second.
 * @stack: Stack list
 * @line_num: Number of line
 */
void _sub(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;
	int sub = 0;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	sub = current->next->n - current->n;
	current->next->n = sub;
	_pop(stack, line_num);
}

/**
 * _nop -  to function void
 * @stack: Stack list
 * @line_num: Number of the line
 */
void _nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
