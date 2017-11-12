/*
   HARDIK RANA
   C program implement binary tree using array 
*/

#include<stdio.h>
int a[100];

void insert(int x,int root)
{
    if(a[root]==0)
    {
         a[root]=x;
         return ;
    }
    printf("Enter 1.to insert left 2.to insert right\n");
    int c;
    scanf("%d",&c);
    if(c==1)
    {
         insert(x,2*root);
    }
    else if(c==2)
    {
         insert(x,2*root+1);
    }
}

void print(int root)
{
    if(a[root]==0)
         return;
    print(2*root);
    printf("%d ",a[root]);
    print(2*root+1);
}

void rd(int root)
{
    if(a[root]==0)
          return;
    a[root]=0;
    rd(2*root);
    rd(2*root+1);
}

void delete(int root)
{
    if(a[root]==0)
    {
         printf("Tree is empty so can't delete\n");
         return;
    }
    printf("Enter 1.to delete 2.to continue\n");
    int c1;
    scanf("%d",&c1);
    if(c1==1)
    {
          rd(root);
          return;
    }
    else if(c1==2)
    {
          printf("Enter 1.to delete in left subtree 2.to delete in right subtree\n");
          int d;
          scanf("%d",&d);
          if(d==1)
          {
               delete(2*root);
               return;
          }
          else if(d==2)
          {
               delete(2*root+1);
               return;
          }
    }
}

int main()
{
    int choice,x;
    while(1)
    {
         printf("Enter\n1.to insert\n2.to delete\n3.to print\n4.to exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
              case 1:
                        printf("Enter no. to be inserted\n");
                        scanf("%d",&x);
                        insert(x,1);
                         break;
               
              case 2:
                        delete(1);
                        break;
               
              case 3:
                        print(1);
                        printf("\n");
                        break;
               
              case 4:
                       exit(1);
         }
    }
   return 0;
}
