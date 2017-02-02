#ifndef __DATA_H__
#define __DATA_H__

#include <stdio.h>
#include <stdint.h>

/****************************************************************
*	File: data.h
*	Dependencies: stdio.h, stdint.h, data.c
*	Description:
*
*
****************************************************************/


/****************************************************************
* int8_t* my_itoa(int8_t* str, int32_t data, int32_t base);
*		
*	Description: Converts signed 32-bit integer data to null terminated
*	ascii character string representation with radix given by parameter 
*	base. Base 2 - Base 36 are supported (who the hell is using Base 36?). 
*	Alphabetic and numeric characters are used to give 36 unique characters.
*	Verifies str is valid (!= NULL). It is up to the user to ensure that str
*	points at a buffer large enough to hold the resulting character string.
*	The size of the buffer pointed at by str should generally be at least
*	ceiling(logb(data)/log10(data)), where logb() is the logarithm whose
*	base is base. The return value is the same as str.
*
*	Parameters:
*		- int8_t* str: Pointer to buffer used to store ascii character string.
*		  It is up to the user to ensure the size of the buffer is large enough.
*		  The buffer must be large enough to hold numerical data in addition to 1
*		  sign byte (only if base == 10 and data < 0) and a null-terminator byte.
*		- int32_t data: Value to be converted into string representation.  
*		- int32_t base: Radix of resultant character string. Can range from 2-36. 
*
*	Return value: int8_t*. The return value points at the same address as str.
*		In case of NULL string being passed in for str or illegal base values used,
*		return value will be NULL (0).
*
*****************************************************************/
int8_t* my_itoa(int8_t* str, int32_t data, int32_t base);



/****************************************************************
* int32_t my_atoi(int8_t* str);		
*	
*	Description: Converts null-terminated ascii character string pointed at by
*	 str into a signed 32-bit integer representation. Returns 0 if str is invalid
*	(NULL). Ignores all non-numeric characters except for a '+' or a '-' if either
*	is found before any numeric characters. Can handle values in range -2147483648
*	to +2147483647. Values outside of this range will lead to unpredicatble results.
*
*	Parameters:
*		- int8_t* str: Pointer to null-terminated character string to be converted
*		  into signed 32-bit integer. Checked for valid address before used. 
*
*	Return value: int32_t. This is the resultant integer value obtained from the
*		conversion process. Will be 0 if str is NULL. Takes on values from -2^31
*		to 2^31 - 1. 
*
*****************************************************************/
int32_t my_atoi(int8_t* str);



/****************************************************************
* int8_t big_to_little32(uint32_t* data, uint32_t length);
*
*	Description: 
*	
*
*	Parameters:
*		- int8_t* str: Pointer to buffer used to store ascii character string.
*		  It is up to the user to ensure the size of the buffer is large enough.
*		  The buffer must be large enough to hold numerical data in addition to 1
*		  sign byte (only if base == 10 and data < 0) and a null-terminator byte.
*		- int32_t data: Value to be converted into string representation.  
*		- int32_t base: Radix of resultant character string. Can range from 2-36. 
*
*	Return value: int8_t*. The return value points at the same address as str.
*		In case of NULL string being passed in for str or illegal base values used,
*		return value will be NULL (0).
*
*****************************************************************/
int8_t big_to_little32(uint32_t* data, uint32_t length);



/****************************************************************
* int8_t* my_itoa(int8_t* str, int32_t data, int32_t base);
*		
*	Description: Converts signed 32-bit integer data to null terminated
*	ascii character string representation with radix given by parameter 
*	base. Base 2 - Base 36 are supported (who the hell is using Base 36?). 
*	Alphabetic and numeric characters are used to give 36 unique characters.
*	Verifies str is valid (!= NULL). It is up to the user to ensure that str
*	points at a buffer large enough to hold the resulting character string.
*	The size of the buffer pointed at by str should generally be at least
*	ceiling(logb(data)/log10(data)), where logb() is the logarithm whose
*	base is base. The return value is the same as str.
*
*	Parameters:
*		- int8_t* str: Pointer to buffer used to store ascii character string.
*		  It is up to the user to ensure the size of the buffer is large enough.
*		  The buffer must be large enough to hold numerical data in addition to 1
*		  sign byte (only if base == 10 and data < 0) and a null-terminator byte.
*		- int32_t data: Value to be converted into string representation.  
*		- int32_t base: Radix of resultant character string. Can range from 2-36. 
*
*	Return value: int8_t*. The return value points at the same address as str.
*		In case of NULL string being passed in for str or illegal base values used,
*		return value will be NULL (0).
*
*****************************************************************/
int8_t little_to_big32(uint32_t* data, uint32_t length);



/****************************************************************
* int8_t* my_itoa(int8_t* str, int32_t data, int32_t base);
*		
*	Description: Converts signed 32-bit integer data to null terminated
*	ascii character string representation with radix given by parameter 
*	base. Base 2 - Base 36 are supported (who the hell is using Base 36?). 
*	Alphabetic and numeric characters are used to give 36 unique characters.
*	Verifies str is valid (!= NULL). It is up to the user to ensure that str
*	points at a buffer large enough to hold the resulting character string.
*	The size of the buffer pointed at by str should generally be at least
*	ceiling(logb(data)/log10(data)), where logb() is the logarithm whose
*	base is base. The return value is the same as str.
*
*	Parameters:
*		- int8_t* str: Pointer to buffer used to store ascii character string.
*		  It is up to the user to ensure the size of the buffer is large enough.
*		  The buffer must be large enough to hold numerical data in addition to 1
*		  sign byte (only if base == 10 and data < 0) and a null-terminator byte.
*		- int32_t data: Value to be converted into string representation.  
*		- int32_t base: Radix of resultant character string. Can range from 2-36. 
*
*	Return value: int8_t*. The return value points at the same address as str.
*		In case of NULL string being passed in for str or illegal base values used,
*		return value will be NULL (0).
*
*****************************************************************/
void print_memory(uint8_t* start, uint32_t length);



#endif /* __DATA_H__ */
