#include "main.h"
#include <unistd.h>
/**
  *basic_int - prints the basic intergers(positive)
  *@x: the interger
  *
  *Return: the number of characters printed
  */
int basic_int(int x)
{
	if (x < 10)
		return (single_char(x + '0'));
	return (basic_int(x / 10) + single_char((x % 10) + '0'));
}
/**
  *print_dint - prints the signed intergers
  *@args: variadic parameter taken as input
  *
  *Return: the number of printed characters
  */
int print_dint(va_list args)
{
	int c, i;
	unsigned int b;

	i = 0;
	c = va_arg(args, int);
	if (c < 0)
	{
		b = (unsigned int) ((c + 1) * -1);
		b = b - 1;
		i += single_char('-');
	}
	else
		b = c;
	return (i + basic_int(b));
}
/**
  *print_bint - prints the intergers in binary format
  *@args: the variadic parameter
  *
  *Return: the number of bytes printed
  */
int print_bint(va_list args)
{
	int c = va_arg(args, unsigned int);
	int b = 0;

	while (c > 0)
	{
		b += single_char((c % 2) + '0');
		c = c / 2;
	}
	if (c == 0)
		b += single_char('0');
	return (b);
}
/**
  *single_char - prints a single char to the stdout
  *@c: the character to be printed
  *
  *Return: number of writen bytes
  */
int single_char(char c)
{
	return (write(1, &c, 1));
}
/**
  *print_uint - prints an unsigned interger to the stdout
  *@args: the variadic parameter
  *
  *Return: the number of characters printed
  */
int print_uint(va_list args)
{
	unsigned int c;

	c = va_arg(args, unsigned int);
	return (basic_int(c));
}
