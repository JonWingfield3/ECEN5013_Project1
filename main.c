#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "memory.h"
#include "data.h"

int main(int argc, char** argv)
{
	int8_t i = 0;
	char* str = "-12341234";
	
	int j = my_atoi(str);
	printf("%d\n", j); 

/*
	print_memory(str, 8);
	big_to_little32((uint32_t*)str, 2);	
	print_memory(str, 8);
	little_to_big32((uint32_t*)str, 2);
	print_memory(str, 8);
*/
	return 0;
}

