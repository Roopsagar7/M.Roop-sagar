#include<stdio.h>
#include<string.h>
#define max 10
int top;
char stack[max];
char push(char x)
{
    
	if(top == (max-1))
		printf("Stack Overflow\n");
	else
		stack[++top] =x;
}
char pop()
{
	if(top == -1)
		printf("Stack is empty\n");
	else
		return stack[top--];
}
main()
{
	char str[20];
	int i;
	top=-1;
	printf("Enter the string : " );
	gets(str);
	for(i=0;i<strlen(str);i++)
		push(str[i]);
	for(i=0;i<strlen(str);i++)
		str[i]=pop();
	printf("Reversed string is : ");
	puts(str);
}