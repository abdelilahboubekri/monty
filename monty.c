#include "monty.h"

global_t global = {NULL, NULL};
/**
 * main - to Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 * Return: number of arguments.
 */

int main(int argc, char *argv[])
{
	if (argc == 2)
		handleargv[1]);
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
/**
 * handle- Read the file
 * @argv: Arguments
 * Return: no Return
 */
void handle(char *argv)
{
	int count = 0, result = 0;
	size_t bufsize = 0;
	char *arguments = NULL, *element = NULL;
	stack_t *stack = NULL;

	global.fd = fopen(argv, "r");
	if (global.fd)
	{
		while (getline(&global.line, &bufsize, global.fd) != -1)
		{
			count++;
			arguments = strtok(global.line, " \n\t\r");
			if (arguments == NULL)
			{
				free(arguments);
				continue;
			}
			else if (*arguments == '#')
				continue;
			element = strtok(NULL, " \n\t\r");
			result = get_opc(&stack, arguments, element, count);
			if (result == 1)
				p_error(global.fd, global.line, stack, count);
			else if (result == 2)
				in_error(global.fd, global.line, stack, arguments, count);
		}
		free(global.line);
		free_dlistint(stack);
		fclose(global.fd);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
/**
 * get_opc - A  function to handle the opcode
 * @stack: A stack or queue
 * @arg: A parameter
 * @element: is a parameter
 * @count: line command
 * Return: no return
 */
int get_opc(stack_t **stack, char *arg, char *element, int count)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"nop", _nop},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (_isdigit(element) == 1)
					value = atoi(element);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)count);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}
