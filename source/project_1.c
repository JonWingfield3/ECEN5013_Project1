#include "../includes/project_1.h"

void project_1_report(void)
{
	uint8_t i = 0;

	//set 1
	uint8_t set1_arr1[32];
	uint8_t set1_arr2[32];
//	uint8_t set1_arr3[32];

	for(i = 0; i < 32; ++i)
	{
		*(set1_arr1 + i) = i % 16;
		*(set1_arr2 + i) = i;
//		*(set1_arr3 + i) = i + 0x61; //converts to ascii
	}


	test_data1(set1_arr1, sizeof(set1_arr1));
	test_data2(set1_arr2, sizeof(set1_arr2));
	test_memory(set1_arr2, sizeof(set1_arr2));
}

void test_data1(uint8_t* arr, uint8_t len)
{
	print_memory(arr, len);
	big_to_little32((uint32_t*)arr, len);
	print_memory(arr, len);
	little_to_big32((uint32_t*)arr, len);
	print_memory(arr, len);
}

void test_data2(uint8_t* arr, uint8_t len)
{
	uint8_t i;
	uint8_t temp_ptr[3];
	int32_t temp_num = 0;
	print_memory(arr, len);
	for(i = 0; i < len; ++i)
	{
		printf("\n");
		my_itoa(temp_ptr, *(arr + i), 10);
		if(i < 0x10) print_memory(temp_ptr, 1);
		else print_memory(temp_ptr, 2);
		*temp_ptr = my_atoi(temp_ptr);
		print_memory(temp_ptr, 1);
	}
}

void test_memory(uint8_t* arr, uint8_t len)
{
	print_memory(arr, len);
	my_reverse(arr, 12);
	my_memset(arr+ 16, 4, 0xEE);
	my_memmove(arr+25,arr+19,6);
	my_memzero(arr+11, 4);
	my_memmove(arr, arr+8, 8);
	print_memory(arr, len);
}
