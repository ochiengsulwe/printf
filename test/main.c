#include <stdio.h>
#include "../main.h"


int main(void)
{
	int len = 0;
	char *text = "This is just a test of mount Kochieng";
	len = _printf("%s\n", text);
	printf("_printf len is: %d\n", len);
	len = printf("%s\n", text);
	printf("printf len is: %d\n", len);
	return (0);
}
