#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
  *print_oint - prints the signed intergers as octal
  *@args: variadic parameter taken as input
  *
  *Return: the number of printed characters
  */
int print_oint(va_list args)
{
	unsigned int c = va_arg(args, unsigned int);

	return (basic_int(c, 8));
}
/**
  *print_xint - prints the hesadecimal number
  *@args: va_list parameter
  *
  *Return: number of printed characters
  */
int print_xint(va_list args)
{
	unsigned int a = va_arg(args, unsigned int);

	return (hexa(a, 'a'));
}
/**
  *print_Xint - prints the X hexadecimal
  *@args: va_list parameter
  *
  *Return: number of printed characters
  */
int print_Xint(va_list args)
{
	unsigned int a = va_arg(args, unsigned int);

	return (hexa(a, 'A'));
}
/**
  *hexa - helper function for the hexa decimal prints
  *@num: unsigned int representation of number
  *@start: should be 'A' or 'a' depending on the calling function
  *
  *Return: the number of printed characters
  */
int hexa(unsigned int num, char start)
{
	if (num < 16)
		return (single_hexa(num, start));
	return (hexa(num / 16, start) + single_hexa(num % 16, start));
}
/**
  *single_hexa - helper function for the hexa function
  *@num: unsigned int representation of the digit
  *@start: should be 'A' or 'a'
  *
  *Return: the number of printed bytes
  */
int single_hexa(unsigned int num, char start)
{
	if (num < 10)
		return (single_char(num + '0'));
	return (single_char((num - 10) + start));
}
