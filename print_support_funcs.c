#include "main.h"
#include <unistd.h>
/**
  *printchar - write character to the stdout.
  *@args: the variadic parameter with input
  *
  *Return: number of characters written
  */
int printchar(va_list args)
{
	int c;

	c = va_arg(args, int);

	return (write(1, &c, 1));
}
/**
  *_putchar - prints characters to the stdout
  *@s: input buffer to be printed
  *@num: the number of characters in the buffer to print
  *
  *Return: the number of printed bytes
  */
int _putchar(char *s, int num)
{
	return (write(1, s, num));
}
/**
  *print_str - write a string to the stdout
  *@args: the variadic parameter with string to print
  *
  *Return: number of characters printed
  */
int print_str(va_list args)
{
	int count = 0;
	char *s = va_arg(args, char *);

	count = _strlen(s);
	return (write(1, s, count));
}

