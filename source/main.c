#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../includes/project_1.h"
#include "../includes/memory.h"
#include "../includes/data.h"

#define PROJECT1

int main(void)
{
	#ifdef PROJECT1
	project_1_report();
	#endif

	return 0;
}
