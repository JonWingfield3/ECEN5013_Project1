#ifndef __PROJECT_1_H__
#define __PROJECT_1_H__

#include <stdio.h>
#include <stdint.h>

#include "memory.h"
#include "data.h"

/********************************************************************
*	File: project_1.h
*
*	Dependencies: memory.h, data.h, stdint.h, stdio.h
*	Description: project1_report() called from main.c. All other functions
* called by project1_report(). The functions take arrays as arguments
* that are used when testing each of the functions in data.c and 
* memory.c. 
*
********************************************************************/

void project_1_report(void);

void test_data1(uint8_t* arr, uint8_t len);

void test_data2(uint8_t* arr, uint8_t len);

void test_memory(uint8_t* arr, uint8_t len);


#endif /* __PROJECT_1_H__ */
