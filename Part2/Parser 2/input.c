#include<stdio.h>
#define rr4re 5
#define dd 99

int main()
{
	int a = 5;
	// Single comment
	char c = 'u';
	/* Multi
	line comment
	*/
	while(a>0)
	{
		/*
		Nested
		/* comment */ 
		/*
		dd
		*/
		*/
		printf("%d",a);
		a--;
		int b = 4;
		while(b>0)
		{
			printf("%d", a*b);
			b--;
		}
	}
}
