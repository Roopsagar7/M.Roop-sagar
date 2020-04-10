 #include <stdio.h>
#include <stdlib.h>
int stack1[100], stack2[100];
int top1 = -1, top2 = -1;
int count = 0;
void create()
{
    top1 = top2 = -1;
}
void push1(int num)
{
    stack1[++top1] = num;
}
int pop1()
{
    return(stack1[top1--]); 
}
void push2(int num)
{
    stack2[++top2] = num; 
}
int pop2()
{
    return(stack2[top2--]);
}
void enqueue()
{
    int data, i;
    printf("Enter the data : ");
    scanf("%d", &data);
    push1(data); 
    count++;
}
void dequeue()
{
    int i;
    for (i = 0;i <= count;i++)
    {
        push2(pop1()); 
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2()); 
    }}
void display()
{
    int i;
    if(top1 == -1)
    {
        printf("\nqueue is empty\n");
    }
    else
    {
        printf("\nqueue elements are : ");
        for (i = 0;i <= top1;i++)
        {
            printf(" %d ", stack1[i]);
        }
        printf("\n");
}}
int main()
{
    int choice;
    printf("\nqueue using two stack implementation\n\n");
    printf("\nEnter your choice 1 for enqueue,2 for dequeue,3 for display and 4 for exit\n");
    create();
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
    }
    
}