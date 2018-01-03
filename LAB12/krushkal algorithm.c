/*
  HARDIK RANA
  
  DSA SEM3-LAB 12
  
*/

// krushkal
#include<stdio.h>

struct node
{
   int u,v,w;
}a[1000],re[1000];

int subset[10000];

void sort(int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
         for(j=i+1;j<n;j++)
         {
             if(a[i].w>a[j].w)
             {
                 struct node tmp=a[i];
                 a[i]=a[j];
                 a[j]=tmp;
             }
         }
    }
}

int find_set(int a)
{
   if(subset[a]==-1)
   return a;
   return find_set(subset[a]);
}

void Union(int x,int y)
{
   int root_x=find_set(x);
   int root_y=find_set(y);
   subset[root_x]=root_y;
}

void main()
{
   int e,n;
   printf("Enter no. of nodes & no. of edges\n");
   scanf("%d %d",&n,&e);
   int i;
   for(i=0;i<e;i++)
   {
       printf("Enter edge from & to & weight\n");
       scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
   }

   for(i=0;i<10000;i++)
   subset[i]=-1;

   sort(e);
   //for(i=0;i<e;i++)
   //printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
   int sum=0,k=0;
   //printf("%d\n",e);
   for(i=0;i<e;i++)
   {

       if(find_set(a[i].u)!=find_set(a[i].v))
       {
       //printf("hi\n");
           sum+=a[i].w;
           re[k]=a[i];
           k++;
           Union(a[i].u,a[i].v);
       }
   }
   printf("minimum sum of weights is %d\n",sum);
   for(i=0;i<k;i++)
   {
       printf("%d,%d = %d\n",re[i].u,re[i].v,re[i].w);
   }
}
