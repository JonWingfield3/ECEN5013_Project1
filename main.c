#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "memory.h"
#include "data.h"

int main(int argc, char** argv)
{
	int8_t str[50];
	my_itoa(str,-2147483648, 16);	
	printf("%s\n", str);
	return 0;
}

