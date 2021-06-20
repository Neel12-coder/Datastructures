#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
struct node *prev;
} node;
node *start=NULL;
node *create(int n)
{
 int i;
node *ptr;
node *x;
start=(node *) malloc(sizeof(node));
printf("Enter Data For First Time");
scanf("%d",&start->data);
start->next=NULL;
start->prev=NULL;
ptr=start;x=start;
for(i=1;i<n;i++)
{
 ptr->next=(node *) malloc(sizeof(node));
 ptr=ptr->next;
 printf("Enter Data For %d Time ",i+1);
 scanf("\n%d",&(ptr->data));
 ptr->next=NULL;
 ptr->prev=x;
 x=ptr;
}
return start;
}
void display()
{
    node *ptr;
 if(start==NULL)
 {
  printf("UNDERFLOW\n");
 }
 else
 {
  printf("Data of Linked List is:\n");
  ptr=start;
  while(ptr!=NULL)
  {
   printf("%d\t",(ptr->data));
   ptr=ptr->next;
  }
 }
}
void iate(int val)
{
 node *ptr;
 int *pre_ptr;
 node *new_node;
 new_node=(node *) malloc(sizeof(node));
 ptr=start;
 while(ptr->next!=NULL)
 {
  ptr=ptr->next;
 }
 new_node->data=val;
 ptr->next=new_node;
 new_node->next=NULL;
 new_node->prev=ptr;
}
node *iatb(int val)
{
 node *ptr;
 node *new_node;
 new_node=(node *) malloc(sizeof(node));
 ptr=start;
 start->prev=new_node;
 new_node->data=val;
 new_node->next=ptr;
 new_node->prev=NULL;
 start=new_node;
 return start;
}
node *del_at_e()
{
 node *ptr;
 ptr=start;
 while(ptr->next!=NULL)
 {
  ptr=ptr->next;
 }
 ptr->prev->next=NULL;
 free(ptr);
 return start;
}
node *del_at_b()
{
 node *ptr;
 ptr=start;
 start=ptr->next;
 start->prev=NULL;
 free(ptr);
 return start;
}
void search(int val)
{
    node *ptr;
    ptr=start;
    while(ptr!=NULL&&(ptr->data)!=val)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at:\t %d",ptr);
    }
}
node *del()
{
 node *ptr;
 ptr=start;
 while(start!=NULL)
 {
  ptr=start;
  start=start->next;
  free(ptr);
 }
 return start;
}
void main()
{
 int val,i,choice=-1,n;
 printf("Enter The No. of Nodes\t: ");
 scanf("%d",&n);
 while(choice!=0)
 {
  printf("\nEnter The choice\n1.Create\n2.Display\n3.Insertion at the end\n4.Insertion at the beg\n5.Deletion at the end\n6.deletion at the beg\n7.Search emt\n8.Delete List\n0.Exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
  	 case 0:
   break;
   case 1:
   start=create(n);
   break;
   case 2:
   display();
   break;
   case 3:
   printf("Enter Element To Be Added");
   scanf("%d",&val);
   iate(val);
   break;
   case 4:
   printf("\nEnter Element To Be Added");
   scanf("%d",&val);
   start=iatb(val);
   break;
   case 5:
    start=del_at_e();
   break;
   case 6:
    start=del_at_b();
   break;
   case 7:
   printf("\nEnter Element To Be Searched:\t");
   scanf("%d",&val);
   search(val);
   break;
   case 8:
   start=del();
   break;
  }
 }
 getch();
}
