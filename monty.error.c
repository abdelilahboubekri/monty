#include "monty.h"

/**
 * push_error - push error (handling)
 * @fd: file desciptor
 * @line: buffer
 * @stack: stack or queue
 * @count: line command
 */
void _push_error(FILE *fd, char *line, stack_t *stack, int count)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", count);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}

/**
 * ins_error - handler the Error 
 * @fd: file descriptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @count: is a line command
 * @element: number
 */
void _han_error(FILE *fd, char *line, stack_t *stack, char *count, int item)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", element, count);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
