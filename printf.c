#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#define BUFFSIZE 1024
/**
  *_printf - variadic function that coordinates the printf program.
  *@format: the string to be printed followed by the formatted options.
  *Description: creates a memory location of size BUFFSIZE, copies content
  *into the location and calls a function putchar to print the contents
  *Return: the number of characters printed.
  */
int _printf(const char *format, ...)
{
	int pnum;
	char *buffer;
	va_list params;

	pnum = 0;
	buffer = create_mem(BUFFSIZE);
	if (buffer == NULL)
		exit(12);
	va_start(params, format);
	if (format == NULL)
		return (0);
	pnum += writeto_buf(format, params, buffer);
	va_end(params);
	free(buffer);
	return (pnum);
}
/**
  *writeto_buf - writes content to the character buffer
  *@buffer: the buffer
  *@args: arguments captured in the va_list
  *@s: the string to be printed
  *Description: writes the string to be printed to a buffer and calls the
  *formatit function if there are any formating involved.
  *Return: the number of bytes written to the buffer.
  */
int writeto_buf(const char *s, va_list args, char *buffer)
{
	const char *temp = s;
	char *buf_id = buffer;
	int pnum, buf_locator;
	char c;

	pnum = buf_locator = 0;
	while ((c = *temp))
	{
		if (c == '%')
		{
			pnum += _putchar(buf_id, buf_locator);
			buf_id = buffer = clear_mem(buf_id, BUFFSIZE);
			buf_locator = 0;
			c = *(++temp);
			if (c == '%')
				pnum += single_char('%');
			else
				pnum += formatit(c, args);
		}
		else
		{
			*buffer++ = c;
			buf_locator++;
		}
		temp++;
	}
	pnum += _putchar(buf_id, buf_locator);
	return (pnum);
}
/**
  *formatit - processes the formating options received
  *@c: the format specifier received after %
  *@args: the stdarg list received from the parent function
  *Description: processes the formating options received.
  *buffer: the buffer to print to.
  *Return: the number of characters pushed to the buffer
  */
int formatit(char c, va_list args)
{
	int nump = 0;
	int (*ptr)(va_list args);

	switch (c)
	{
		case 'c':
			ptr = &printchar;
			break;
		case 's':
			ptr = &print_str;
			break;
		case 'i':
		case 'd':
			ptr = &print_dint;
			break;
		case 'b':
			ptr = print_bint;
			break;
		case 'u':
			ptr = print_uint;
			break;
		case 'o':
			ptr = print_oint;
			break;
		case 'x':
			ptr = print_xint;
			break;
		case 'X':
			ptr = print_Xint;
			break;
		case 'p':
			ptr = print_p;
			break;
		default:
			nump += single_char('%');
			nump += single_char(c);
			break;
	}
	nump += ptr(args);
	return (nump);
}
