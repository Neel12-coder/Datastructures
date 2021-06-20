#include<stdio.h>

int partition(int a[],int p,int r)
{
   int x,i,j,temp;
   x=a[r];
   i=p-1;
   for(j=p;j<=r-1;j++)
   {
   if(a[j]<=x)
   {
       i++;
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
   }
   i=i+1;
   temp=a[i];
   a[i]=a[r];
   a[r]=temp;
   return i;
   }
}

void quick_sort(int a[],int p,int r)
{
    int q;
   if(p<r)
   {
   q=partition(a,p,r);
   quick_sort(a,p,q-1);
   quick_sort(a,q+1,r);
   }
}

int main()
{
    int n,a[50],i;


    printf("enter how many elements(not more than 50)\n ");
    scanf("%d",&n);
    printf("enter elements one by one\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
        quick_sort(a,0,n-1);

        printf("sorted elements are:\n");

        for(i=0;i<n;i++){
        printf("%d\n",a[i]);
        }
        return 0;
}



