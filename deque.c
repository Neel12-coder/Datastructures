#include<stdio.h>
#include<malloc.h>
typedef struct node{
int data;
struct node*next;
}NODE;
NODE *front;
NODE *rear;
int insert_rear(int x)
{
NODE *ptr;
 ptr=(NODE*)malloc(sizeof(NODE));
 if(ptr==NULL)
 {
     printf("Linked list is fl\n");
     return 0;
 }
 ptr->data=x;
 ptr->next=NULL;
 if(front==NULL)
 {
front=rear=ptr;
return 1;
 }
 rear->next=ptr;
 rear=ptr;
 return 1;
 }
 int insert_front(int x)
 {
 NODE *ptr;
 ptr=(NODE*)malloc(sizeof(NODE));
 if(ptr==NULL)
 {
     printf("Linked list is fl\n");
     return 0;
 }
 ptr->data=x;
 ptr->next=NULL;
 if(front==NULL)
 {
front=rear=ptr;
return 1;
 }
 ptr->next=front;
 front=ptr;
 return 1;
 }
 int delete_front()
 {
    NODE *p;
    int x;
    if(front==NULL)
    {
        printf("Nothing is there to delete in queue\n");
        return -65536;
    }
    p=front;
    front=front->next;
    p->next=NULL;
    x=p->data;
    free(p);
    return x;
    }
int delete_rear()
{
NODE *p,*prev;
int x;
if(front==NULL)
    {
        printf("Nothing is there to delete in queue\n");
        return -65536;
    }
    p=front;
    prev=NULL;
    while(p->next!=NULL)
    {
    prev=p;
    p=p->next;
    }
    prev->next=NULL;
    rear=prev;
    x=p->data;
    free(p);
    return x;

}
void main()
{
int x,ch,val,y;
do
{
printf("enter 1.INPUTRESTRICTED 2.OUTPUTRESTRICTED 0.to exit\n");
scanf("%d",&x);
switch(x)
{
case 1:do{
    printf("Enter 1.insert 2.delete from front 3.delete from end 4.exitinner\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: printf("enter value\n");
           scanf("%d",&val);
           y=insert_rear(val);
           if(y==1)
           printf("%d has been inserted\n",val);
           else
           printf("Insertion fail");
           break;
     case 2:y=delete_front();
              if(y==-65536)
           printf("DELETION FAIL\n");
           else
           printf("%d has been deleted\n",y);
           break;
     case 3:y=delete_rear();
              if(y==-65536)
           printf("DELETION FAIL\n");
           else
           printf("%d has been deleted\n",y);
           break;
     case 4:break;
    }
    }while(ch!=4);break;
 case 2:do{
        printf("Enter 1.insert from front 2.insert from end  3.delete from front 4.exitinner \n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: printf("enter value\n");
           scanf("%d",&val);
           y=insert_front(val);
           if(y==1)
           printf("%d has been inserted\n",val);
           else
           printf("Insertion fail");
           break;
    case 2: printf("enter value\n");
           scanf("%d",&val);
           y=insert_rear(val);
           if(y==1)
           printf("%d has been inserted\n",val);
           else
           printf("Insertion fail");
           break;
     case 3:y=delete_front();
              if(y==-65536)
           printf("DELETION FAIL\n");
           else
           printf("%d has been deleted\n",y);
           break;
     case 4:break;
}}
while(ch!=4);
 case 0: break;
 }

}while(x!=0);
}
