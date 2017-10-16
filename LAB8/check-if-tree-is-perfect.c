#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *left,*right;
}*root;

struct node *newNode(int x)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

int findDepth(struct node *temp)
{
    int d=0;
    while(temp!=NULL)
    {
        d++;
        temp=temp->left;;
    }
    return d;
}

bool IsPerfect(struct node *temp,int d,int level)
{
    if(temp==NULL)
        return true;
    if(temp->left==NULL&&temp->right==NULL)
        return d==level;
    if(temp->left==NULL||temp->right==NULL)
        return false;
    return (IsPerfect(temp->left,d,level+1)&&IsPerfect(temp->right,d,level+1));
}

int main()
{
    root=newNode(1);

    root->left=newNode(2);
    root->right=newNode(3);

    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    struct node *temp=root;
    int d=findDepth(temp);

    temp=root;
    if(IsPerfect(temp,d,1))
        printf("Tree is perfect\n");
    else
        printf("Tree is not perfect\n");
    return 0;
}
