/* 
   HARDIK RANA
    
    DSA SEM 3-LAB 10

    program to check if a given binary tree is bst or not
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *left,*right;
}*root;


bool isBST(struct node *temp,int min ,int max)
{
    if(temp==NULL)
        return true;
     
    if(temp->data < min || temp->data > max )
    	return false;
    
    return (isBST(temp->left,min,temp->data-1)&&isBST(temp->right,temp->data+1,max)); 
    
}

void Insert(int x,struct node *temp,struct node *prev)
{
    if(temp==NULL)
    {
        struct node *ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=x;
        ptr->left=NULL;
        ptr->right=NULL;
        root=ptr;
        return ;
    }

    int c;
    printf("To Insert To left enter 1 or to right insert 2 :");
    scanf("%d",&c);
    if(c==1)
    {
        if(temp->left==NULL)
        {
          struct node *ptr=(struct node*)malloc(sizeof(struct node));
          ptr->data=x;
          ptr->left=NULL;
          ptr->right=NULL;
          temp->left=ptr;
          return ;
        }
        Insert(x,temp->left,temp);
    }
    else
    {
        if(temp->right==NULL)
        {
          struct node *ptr=(struct node*)malloc(sizeof(struct node));
          ptr->data=x;
          ptr->left=NULL;
          ptr->right=NULL;
          temp->right=ptr;
          return ;
        }
        Insert(x,temp->right,temp);
    }
    return ;
}

int main()
{

         int x,c;
         struct node *temp=NULL,*prev=NULL;
         printf("1]Insert in tree\n2]Check whether BST or not\n3]Exit\n");
         while(1)
         {
             printf("\nEnter your choice:");
             scanf("%d",&c);
             switch(c)
             {
                case 1:
                       printf("Enter the element want to insert :");
                       scanf("%d",&x);
                       temp=root;prev=root;
                       Insert(x,temp,prev);
                       break;
                case 2:
                       temp=root;
                       if(isBST(temp,-10000,10000))
                          printf("Tree is BST\n");
                       else
                        printf("Not BST\n");
                       break;
                case 3:
                       exit(1);
             }
         }
     }
