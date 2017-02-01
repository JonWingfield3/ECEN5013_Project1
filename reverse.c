#include <stdio.h>
char reverse(char* str, int length);

int main(void)
{
	char hello [] = {'h','e','l', 'l', 'o'};
	printf("%s\n", hello);
	reverse(hello, sizeof(hello));
	printf("%s\n", hello);
	
	

	return 0;
}

char reverse(char* str, int length)
{
	int i;
	char c;
	if(str && length > 0)		
	{
		for(i = 0; i < length/2; ++i){
			c = *(str + length - 1 -i);
			*(str + length - 1 - i) = *(str + i);
			*(str + i) = c;
		}
		return 0;
	}			
	else return -1;
}

//Hello World
