#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1,s[MAX];
void push(int [],int);
void pop(int [],int);
void peek(int []);
void display(int []);
void main()
{
int choice,val,a;
while(choice!=0)
{
printf("\nEnter 1 for push\nEnter 2 to pop\nEnter 3 to peep\nEnter 4 to display\nEnter 0 to exit\n");
printf("Enter choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
    {
        printf("Enter the number you want to enter");
    scanf("%d",&val);
    push(s,val);
    break;
    }
case 2:
    {
        pop(s,val);
if(val==-1)
    printf("Could not perform pop operation");
else
    printf("The value %d has been popped out",val);
    break;
    }
case 3:
    peek(s);
    if(a==-1)
   printf("No element present");
   else
    printf("The value  peek is %d\n",a);
    break;
case 4:
    display(s);
    break;

}
}
}
void push(int s[],int val)
{
    if(top==MAX-1)
    {
        printf("Overflow\n");
           }
    else
        {
            top=top+1;
            s[top]=val;
        }

}
 pop(int s[],int v)
{
    if(top==-1)
    {
        printf("Underflow\n");
            }
    else
        {
        v=s[top];
    top=top-1;
    return v;
    }
}
void peek(int s[])
{
    if(top==-1)
       {
           printf("No element present in the stack");
       return -1;
       }
    else
        return s[top];

}
void display(int s[])
{

    int i;
    if(top==-1)
        printf("Under flow\nNo element present");
    else
    {
        for(i=top;i>=0;i--)
        {

            printf("%d\t",s[i]);
        }

    }
}
