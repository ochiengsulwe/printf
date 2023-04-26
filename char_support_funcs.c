#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"
/**
  *create_mem - creates memory of size size.
  *@size: the size of memory to create
  *
  *Return: NULL if failed, or pointer to the memory location
  */
char *create_mem(size_t size)
{
	char *p = NULL;

	p = malloc(size);
	if (p == NULL)
		return (NULL);
	return (p);
}
/**
  *clear_mem - sets memory space to null
  *@s: the block of memory of type char *
  *@size: size of the block
  *
  *Return: the pointer to the begining of the memory block
  */
char *clear_mem(char *s, size_t size)
{
	char *temp = s;
	size_t i = 0;

	while (i++ < size)
		*temp++ = '\0';
	return (s);
}
/**
  *_strlen - checks the length of a string
  *@s: char pointer to the string
  *
  *Return: the length of the string
  */
int _strlen(char *s)
{
	int len = 0;

	while (*s++ != '\0')
		len++;
	return (len);
}
