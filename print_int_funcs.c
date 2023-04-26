#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
  *basic_int - prints the basic intergers(positive)
  *@x: the interger
  *@base: the base of the interger
  *
  *Return: the number of characters printed
  */
int basic_int(unsigned int x, unsigned int base)
{
	if (x < base)
		return (single_char(x + '0'));
	return (basic_int((x / base), base) + single_char((x % base) + '0'));
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
		b = b + 1;
		i += single_char('-');
	}
	else
		b = c;
	return (i + basic_int(b, 10));
}
/**
  *print_bint - prints the intergers in binary format
  *@args: the variadic parameter
  *
  *Return: the number of bytes printed
  */
int print_bint(va_list args)
{
	unsigned int c = va_arg(args, unsigned int);

	return (basic_int(c, 2));
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
	return (basic_int(c, 10));
}
