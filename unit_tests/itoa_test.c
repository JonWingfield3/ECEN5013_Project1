#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../memory.h"
#include "../data.h"

int main(void)
{
	int32_t i;
	int8_t s[15];
/*
	i = 54321;
	printf("data is: %x \nstring is: %s\n",i, my_itoa(s,i,16));
	
	i = 2147483647;
	printf("data is: %x \nstring is: %s\n",i, my_itoa(s,i,16));
	
	i = -5000;
	printf("data is: %x \nstring is: %s\n",i, my_itoa(s,i,16));
	
	i = -3;
	printf("data is: %x \nstring is: %s\n",i, my_itoa(s,i,16));
	
	i = -2147483648;
	printf("data is: %x \nstring is: %s\n", i, my_itoa(s,i,16));

	i = -0;
	printf("data is: %x \nstring is: %s\n",i, my_itoa(s,i,16));

	i = 50000;
	printf("data is: %x \nstring is: %s\n",i, my_itoa(s,i,16));

	i = 504030201;
	printf("data is: %d \nstring is: %s\n",i, my_itoa(s,i,10));
	printf("data is: %o \nstring is: %s\n",i, my_itoa(s,i,8));
	printf("data is: %x \nstring is: %s\n",i, my_itoa(s,i,16));

	i = -45;
	printf("data is: %o \nstring is: %s\n",i, my_itoa(s,i,8));
*/
	uint8_t temp_ptr[2];

	i = 1;
	my_itoa(temp_ptr, i, 10);
	print_memory(temp_ptr,1);

	return 0;
}
