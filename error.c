#include "monty.h"

/**
 * p_error - handle push error
 * @fd: a file desciptor
 * @line: is a buffer
 * @stack: a stack or queue
 * @count: a line command
 */
void p_error(FILE *fd, char *line, stack_t *stack, int count)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", count);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}

/**
 * ins_error - to hadle the Error 
 * @line: is a buffer
 * @fd: a file descriptor
 * @stack: is a stack or queue
 * @count: is a line command
 * @element: number
 */
void in_error(FILE *fd, char *line, stack_t *stack, char *count, int element)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", element, count);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
