#include "memory.h"

#define PTR_ERROR   -1
#define SUCCESS      0

int8_t my_memmove(uint8_t* src, uint8_t* dst, uint32_t length)
{
	
	uint32_t i;
	if( !src || !dst ) return PTR_ERROR;
	
	if(src > dst)
	{
		for(i = 0; i < length; ++i)
			dst[i] = src[i];	
	}
	else if(src < dst)
	{
		for(i = 0; i < length; ++i)
			src[i] = dst[i];
	}
	return SUCCESS;
	
}
int8_t my_memset(uint8_t* src, uint32_t length, uint8_t value)
{
	uint32_t i;
	if( !src ) return PTR_ERROR;
	
	for(i = 0; i < length; ++i)
		src[i] = value;

	return SUCCESS;
}	
	
int8_t my_memzero(uint8_t* src, uint32_t length)
{
	uint32_t i;
	if( !src ) return PTR_ERROR;
	
	for(i = 0; i < length; ++i)
		src[i] = 0;

	return SUCCESS;
}

int8_t my_reverse(uint8_t* src, uint32_t length)
{
	if( !src ) return PTR_ERROR;
    uint32_t i;
	uint8_t temp;		
	
	for(i = 0; i < length >> 1; ++i)
	{
		temp = src[i];
		src[i]= src[length - 1 - i];
		src[length -1 -i] = temp;
	}		
	return SUCCESS;
}
