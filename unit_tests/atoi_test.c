#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../memory.h"
#include "../data.h"

int main(int argc, char** argv)
{
    int8_t i = 0;
    char* test_strings[ ] = {"1",
							 "0",
							 "-1",
							 "-0",
							 "  ",
							 "abcdef",
							 "12341234",
							 "-12341234",
							 "0xabc154",
						     "how are you?",
							 "2147483647", // max value
							 "-2147483648", // min value
							 "a0a0a0a0a0"};


	for(i = 0; i < 13; ++i)
		printf("test %i: string is: %s, my_atoi returns: %d\n", i, test_strings[i], my_atoi(test_strings[i]));

    return 0;
}
