#ifndef PRINT_H
#define PRINT_H
#include <stdarg.h>
#include <stddef.h>
int _printf(const char *format, ...);
int writeto_buf(const char *s, va_list args, char *buffer);
int printchar(va_list args);
int _putchar(char *s, int num);
int formatit(char c, va_list args);
char *create_mem(size_t size);
char *clear_mem(char *s, size_t size);
int print_str(va_list args);
int _strlen(char *s);
int basic_int(int x);
int print_dint(va_list args);
int single_char(char c);
int print_bint(va_list args);
int print_uint(va_list args);
#endif
