#include "monty.h"

int _usage_error(void);
int _malloc_error(void);
int file_open_error(char *filename);
int no_int_error(unsigned int line_num);
int unknown_op_error(char *opcode, unsigned int line_num);
void set_op_tok_error(int error_code);

/**
 * _usage_error - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */

int _usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * _malloc_error - function Prints malloc messages of errors
 *
 * Return: (EXIT_FAILURE) always.
 */

int  _malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_error - function Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */

int file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - it Prints invalid monty_push argument error messages.
 * @line_num: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	return (EXIT_FAILURE);
}
/**
 * unknown_op_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_num: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int unknown_op_error(char *opcode, unsigned int line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_num, opcode);
	return (EXIT_FAILURE);
}

/**
 * set_op_tok_error - it Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		_malloc_error();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		_malloc_error();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
