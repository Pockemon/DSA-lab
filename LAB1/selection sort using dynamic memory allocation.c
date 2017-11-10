#include<stdlib.h>
#include<stdio.h>
int main(){
int i,j,c,n,*a;
printf("Enter n\n");
scanf("%d",&n);
a=malloc(n*sizeof(int));
if(a!=NULL)
{
printf("enter elements of array\n");
for(i=0;i<n;i++)
{
 scanf("%d",& *(a+i));
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(*(a+i)>*(a+j))
{
c=*(a+i);
*(a+i)=*(a+j);
*(a+j)=c;
}
}
}

printf("Sorted array using selection sort is\n");
for(i=0;i<n;i++)
printf("%d ",*(a+i));
printf("\n");
}
else
printf("Memory allocation failed\n");
free(a);
return 0;
}
