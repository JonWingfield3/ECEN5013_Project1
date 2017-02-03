#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../memory.h"
#include "../data.h"
#define ARR_LENGTH 10

int main(int argc, char** argv)
{
	uint8_t i;
	uint8_t* src, *dst;
	uint8_t value = 0xFF;
	uint32_t length;
	
	// my_memmove tests
	printf("my memmove tests\n\n");
	uint8_t arr_src [] = {1,2,3,4,5,6,7,8,9,10};
	uint8_t arr_dst [ARR_LENGTH];

	src = arr_src;
	dst = arr_dst;
	
	//copy arr_src to arr_dst and print results
	my_memmove(src, dst, ARR_LENGTH);
	printf("source: ");
	print_memory(src, ARR_LENGTH);
	printf("\n");
	printf("dst after call to my_memmove: ");
	print_memory(dst, ARR_LENGTH);

	// my_memset tests
	printf("\nmy memset tests\n\n");
	my_memset(dst, ARR_LENGTH, value);
	printf("setting buffer to FF's, result: ");
	print_memory(dst, ARR_LENGTH);
	value = 0xEE;
	printf("\nsetting buffer to EE's, result: ");
	my_memset(dst, ARR_LENGTH, value);
	print_memory(dst, ARR_LENGTH);
	printf("\n\n");

	// my_memzero tests
	printf("my_memzero tests\n\n");
	printf("before: ");
	print_memory(dst, ARR_LENGTH);
	printf("\nAfter: ");
	my_memzero(dst, ARR_LENGTH);
	print_memory(dst, ARR_LENGTH);
	printf("\n\n");	
	// my_reverse


	return 0;
}

