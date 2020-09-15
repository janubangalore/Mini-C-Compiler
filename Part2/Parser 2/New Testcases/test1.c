#include<stdio.h>
int multi(int b)
{
return 3*b;
}

int main()
{
    int a=10,b=0;
    char ch;//Single line comment
    while(a>0)
    {
       b+=a;
       a=a-1;
    /*
    This is Multi-Line
    Comment..
    */
    }
    int x=multi(b); //Function call
    return 0;
}
