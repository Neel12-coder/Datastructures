#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int rear=-1,front=-1,s[MAX];
void enqueue(int [],int);
void dequeue(int []);
void display(int []);
void main()
{
int choice,a;
while(choice!=0)
{
printf("\nEnter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to display\nEnter 0 to exit\n");
printf("Enter choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
    printf("Enter the number you want to enqueue\n");
    scanf("%d",&a);
 enqueue(s,a);
break;
case 2:
    dequeue(s);
    break;
case 3:
    display(s);
    break;
}
}
}
void enqueue(int s[],int a)
{
    if(rear==MAX-1)
        printf("Overflow");
   else if(rear==-1 && front==-1)
     {
         front=0;
    rear=0;
    s[rear]=a;
    printf("inserted successfully\n");
     }
    else

        {rear=rear+1;
    s[rear]=a;
    printf("inserted successfully\n");
}
}
void dequeue(int s[])
{
    printf("Dequeing the queue");
    if(front==-1 || front>rear)
        printf("Underflow");
    else
        {

    front=front+1;
    printf("deleted successfully\n");

}
}
void display(int s[])
{

    int i;
if(front == -1 || front > rear)
printf("\n QUEUE IS EMPTY");
else
{
for(i = front;i <= rear;i++)
printf("\t %d", s[i]);
}
}

