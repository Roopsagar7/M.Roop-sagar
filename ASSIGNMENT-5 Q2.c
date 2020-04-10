 #include <stdio.h>
#include <ctype.h>
#define max 10           
char stack[max];
int top;       
int push(char x)
{                       
    stack[++top]=x;
}
char pop()
{                      
    return(stack[top--]);
}
int pr(char symbol)
{                 
    
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void main()
{                        
    char infix[10],postfix[10];
    char x,ch;
    top=-1;
    int i=0,k=0;
    printf("Enter Infix Expression : ");
    scanf("%s",infix);
    push('#');
    while( (ch=infix[i++]) != '\0')
    {
        if( ch == '(') push(ch);
        else
            if(isalnum(ch)) postfix[k++]=ch;
            else
                if( ch == ')')
                {
                    while( stack[top] != '(')
                        postfix[k++]=pop();
                    x=pop();
                }
                else
                {       
                    while( pr(stack[top]) >= pr(ch) )
                        postfix[k++]=pop();
                    push(ch);
                }
    }
    while( stack[top] != '#')     
        postfix[k++]=pop();
    postfix[k]='\0';          
    printf("Postfix Expression =  %s\n",postfix);
}
