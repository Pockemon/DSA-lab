/*
  HARDIK RANA
  
  DSA SEM3-LAB1
  
*/

#include<stdlib.h>
#include<stdio.h>
int main(){
int c,n,*a,i,j;
printf("Enter n\n");
scanf("%d",&n);
a=malloc(sizeof(int)*n);
if(a!=NULL)
{
printf("Enter elements of array\n");
for(i=0;i<n;i++)
{scanf("%d",& *(a+i));}
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(*(a+j)>*(a+j+1))
{
c=*(a+j);
*(a+j)=*(a+j+1);
*(a+j+1)=c;
}
}
}
printf("sorted array using bubble sort is\n");
for(i=0;i<n;i++)
printf("%d ",*(a+i));
printf("\n");
}
else
printf("memory allocation failed\n");
free(a);

return 0;
}
