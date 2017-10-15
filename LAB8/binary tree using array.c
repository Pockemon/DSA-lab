//Binary Tree using Array

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int Tree[123456];

bool Search(int x,int root)
{
    if(Tree[root]==0)
        return false;
    if(Tree[root]==x)
        return true;
    return Search(x,2*root)||Search(x,2*root+1);
}

void Insert(int x,int root)
{
    if(Tree[root]==0)
    {
        Tree[root]=x;
        return ;
    }
    int c;
    printf("To Insert left enter 1 for right press 2 : ");
    scanf("%d",&c);
    if(c==1)
        Insert(x,2*root);
    else
        Insert(x,2*root+1);
}

void really_delete(int root)
{
    int temp;
    if(Tree[2*root]==0&&Tree[2*root]==0)
    {
        Tree[root]=0;
        return ;
    }
    if(Tree[2*root]||Tree[2*root+1]==0)
    {
        temp=Tree[root];
        Tree[root]=Tree[2*root];
        Tree[2*root]=temp;
        really_delete(2*root);
    }
    if(Tree[2*root+1])
    {
        temp=Tree[root];
        Tree[root]=Tree[2*root+1];
        Tree[2*root+1]=temp;
        really_delete(2*root+1);
    }
}

void Delete(int root)
{
    if(Tree[root]==0)
    {
        printf("No element Present for deletion :-)\n");
        return ;
    }
    char c;int arr;
    printf("Want to delete this item:");
    scanf(" %c",&c);
    if(c=='y')
    {
        really_delete(root);
    }
    else
    {
         printf("To Insert left enter 1 for right press 2 : ");
         scanf("%d",&arr);
         if(arr==1)
            return Delete(2*root);
         else
            return Delete(2*root+1);
    }

}

int main()
{
    int x,c;
    printf("1]Insert\n2]Delete\n3]Search\n4]Exit\n");
    while(1)
    {
           printf("Enter the choice :");
           scanf("%d",&c);
           switch(c)
           {
               case 1:
                       printf("Enter the element want to insert :");
                       scanf("%d",&x);
                       Insert(x,1);
                       break;
               case 2:
                       Delete(1);
                       break;
               case 3:
                      printf("Enter the element want to search :");
                      scanf("%d",&x);
                      if(Search(x,1))
                        printf("%d is present\n",x);
                      else
                        printf("%d isn't present\n",x);
                      break;
               case 4:
                      exit(1);
           }
    }
}
