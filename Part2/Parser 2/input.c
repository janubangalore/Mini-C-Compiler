#include<stdio.h>
int main()
{
	int a = 5;
	int h[5];
	//Hello
	char c = 'u';
	char ii[4+a];
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
		int b;
		while(b>0)
		{
			printf("%d", a*b);
			b--;
		}
	}
}
