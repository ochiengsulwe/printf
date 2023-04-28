#include <stdio.h>
#include "main.h"
/**
  *print_p - prints a pointer
  *@args: input of type va_arg
  *
  *Return: number of printed characters
  */
int print_p(va_list args)
{
	size_t a;
	char *s = "0x";

	a = va_arg(args, size_t);
	return (_putchar(s, 2) + p_hexa(a));
}
/**
  *p_hexa - prints the hexa decimal number recursively
  *@a: the number to be printed in hexa decimal
  *
  *Return: number of printed characters
  */
int p_hexa(size_t a)
{
	if (a < 16)
		return (single_hexa((unsigned int)a, 'a'));
	return (p_hexa(a / 16) + single_hexa((unsigned int)(a % 16), 'a'));
}
