#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
} node;

node *start=NULL;
void display(node *ptr)
{
    printf("\nelements are\n");
while(ptr!=NULL)
{
printf("%d ",ptr->data);
ptr=ptr->next;
}
}

void insert_beg(node *start)
{
 node *ptr;
ptr=start;
node* new_node;
new_node=(node *) malloc(sizeof(node));
printf("enter the data\n");

scanf("%d",&new_node->data);
start=new_node;
new_node->next=ptr;

}
void insert_end(node *start)
{
 node *ptr;
ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
node*new_node;
new_node=(node *) malloc(sizeof(node));
printf("enter the data\n");

scanf("%d",&new_node->data);
ptr->next=new_node;

new_node->next=NULL;

}
void delete_end(node *start)
{
 node *ptr,*preptr;
ptr=start;
preptr=start;

while(ptr->next!=NULL)
{preptr=ptr;
ptr=ptr->next;

}
preptr->next=NULL;
free(ptr);



}
void delete(node *start,int val)
{
 node *ptr,*preptr;
ptr=start;
preptr=start;
while(ptr->data!=val)
{preptr=ptr;
ptr=ptr->next;

}
preptr->next=ptr->next;
free(ptr);
}

void delete_beg(node *start)
{
 node *ptr;
ptr=start;
start=ptr->next;
free(ptr);



}

void count(node *ptr)
{
int i=0;
while(ptr!=NULL)
{i++;
ptr=ptr->next;
}
 printf("no of nodes are %d \n",i);
}


int search(node *ptr)
{   int s,c=1;
node *p;
p=ptr;
printf("enter the element to  be search\n ");
scanf("%d",&s);
 while(p!=NULL)
 { if((p->data)==s)
   return c;
   else
{p=p->next;
 c++;
 }
 }
 return -1;
 }


node *create(int n)
{

int i;
node *ptr;
start=(node *) malloc(sizeof(node));

printf("enter the data for first node\n");
scanf("%d",&(start->data));
start->next=NULL;
ptr=start;
for(i=1;i<n;i++)
{
ptr->next=(node*)malloc(sizeof(node));
ptr=ptr->next;
printf("enter the data for %d\n",i);
scanf("%d",&(ptr->data));
ptr->next=NULL;
}
return start;
}


void main()
{
     node *start;
int i,n,c=-1;
printf("\nenter no of nodes\n");
scanf("%d",&n);
do
{

printf("\nENTER YOUR CHOICE \n1 create \n 2 display \n 3 search \n 4.count\n 5.insertion link list at the beg\n 6. insertion in link list at the end \n 7.deletion from start.\n 8. deletion from end\n 9.delete a given node\0.exit");
scanf("%d",&c);
switch(c)
{
case 1 :
      {
     start=create(n);
      break;
      }
case 2:
     {
     display(start);
     break;
     }
case 3:
    {
        int loc=search(start);
        printf("loc is %d",loc);
          break;
    }
case 4:
    {   count(start);
        break;
    }

case 5:
    {
    insert_beg(start);
     break;
    }

case 6:
    {
    insert_end(start);
    break;
    }

case 7:
    {
    delete_beg(start);
    break;
    }
case 8:
    {
    delete_end(start);
    break;
    }
case 9:
{

    int val;
    printf("enter the value to be deleted\n");
    scanf("%d",&val);
    delete(start,val);
    break;
    }
case 10:
    {

    break;
    }



}
}while(c!=10);
}
