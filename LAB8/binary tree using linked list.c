//Binary Tree Linked List

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *left,*right;
}*root;

void really_delete(struct node *temp,struct node *prev)
{
    if(temp->left==NULL&&temp->right==NULL)
    {
        prev->left=NULL;
        prev->right=NULL;
        //printf("final\n");
        free(temp);
        return ;
    }
    if(temp->left!=NULL||temp->right==NULL)
    {
            int arr=temp->data;
            temp->data=temp->left->data;
            temp->left->data=arr;
            really_delete(temp->left,temp);
    }
    if(temp->right!=NULL)
    {
            int arr=temp->data;
            temp->data=temp->right->data;
            temp->right->data=arr;
            really_delete(temp->right,temp);
    }
}

void Insert(int x,struct node *temp,struct node *prev)
{
    if(root==NULL)
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

bool Search(struct node *temp,int x)
{
    if(temp==NULL)
        return false;
    if(temp->data==x)
        return true;
    return Search(temp->left,x)||Search(temp->right,x);
}

void Delete(struct node *temp)
{
    if(temp==NULL)
    {
        printf("Element not present\n");
        return ;
    }
    char c;int x;
    printf("Do you want to delete %d [y/n]?",temp->data);
    scanf(" %c",&c);
    if(c=='y')
    {
        really_delete(temp,temp);
        return ;
    }
    else
    {
        printf("To go left enter 1 or to go right enter 2:");
        scanf("%d",&x);
        if(x==1)
            Delete(temp->left);
        else
            Delete(temp->right);
    }
}

int main()
{
    int x,c;
    struct node *temp,*prev;
    printf("1]Insert\n2]Delete\n3]Search\n4]Exit\n");
    while(1)
    {
        printf("Enter the choice :");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                    printf("Enter the element want to Insert: ");
                    scanf("%d",&x);
                    temp=root;prev=root;
                    Insert(x,temp,prev);
                    break;
            case 2:
                    temp=root;
                    Delete(temp);
                    break;
            case 3:
                    printf("Enter the element want to search :");
                    scanf("%d",&x);
                    temp=root;
                    if(Search(temp,x))
                        printf("%d is present\n",x);
                    else
                        printf("%d is not present\n",x);
                    break;
            case 4:
                    exit(1);
        }
    }
}
