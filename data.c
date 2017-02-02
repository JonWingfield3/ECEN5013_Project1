#include "data.h"
#define NULL_PTR_ERROR -1

#define IS_NUM(X) (0x30 <= X && X <= 0x39)
#define NUM_2_ASCII(X) (X + 0x30)

int8_t* my_itoa(int8_t* str, int32_t data, int32_t base)
{
	int8_t* digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	uint32_t index = 0;
	uint32_t order = base;

	if(!str || base <= 1 || base > 36) return 0;
	if(data < 0 && base == 10)
	{
		str[index++] = '-';
	//	data = -data;
	}
	if(data < base) str[index++] = digits[data];
	else
	{
		while(data/(base*order) != 0)
			order *= base;

		while(data >= base)
		{
			str[index++] = digits[data/order];
			data %= order;
			order /= base;
			while(data < order)
			{	
				str[index++] = digits[data/order];
				order /= base;
			}
		}
		if(data) str[index++] = digits[data];	
	}
	str[index] = '\0';
	return str;	
}

int32_t my_atoi(int8_t* str)
{
	uint32_t i;
	int8_t sign = 1;
	uint32_t value = 0;
	if(!str) return 0;
		
	for(i = 0; str[i] != '\0'; ++i)
	{
		if(IS_NUM(str[i]))
			value = 10*value + str[i];
		else if(!value && str[i] == '-') sign = -1;
	}
	return sign*value;
}
/*
int8_t big_to_little32(uint32_t* data, uint32_t length)
{

}

int8_t little_to_big32(uint32_t* data, uint32_t length)i
{

}

void print_memory(uint8_t* start, uint32_t length)
{

}
*/
