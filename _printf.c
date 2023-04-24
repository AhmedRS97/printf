#include "test.h"


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _printf - print strings according to format
 * @format: string containing format
 *
 * Return: On success 0.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, j;

	va_start(ap, format);

	for (i = 0; format[i] != '\0'; ++i)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				_putchar(va_arg(ap, int));
			else if (format[i + 1] == 's')
			{
				char *string_arg = va_arg(ap, char*);

				for (j = 0; string_arg[j] != '\0'; ++j)
					_putchar(string_arg[j]);
			}
			else
				_putchar(format[i]);
			++i;
		}
		else
			_putchar(format[i]);
	}
	va_end(ap);
	return (0);
}
