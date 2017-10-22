#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
struct node* newnode(int data);
int isbst(struct node* root);
int isbstutil(struct node* root,int min,int max);

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int main()
{
    struct node* root= newnode(10);
    root->left = newnode(7);
    root->right = newnode(12);
    root->left->left = newnode(6);
    root->left->right = newnode(8);
    root->right->left = newnode(11);
    root->right->right = newnode(13);

    if(isbst(root))
        printf("given binary tree is binary search tree\n");
    else
        printf("given binary tree is not a binary search tree\n");

    return 0;

}

struct node* newnode(int data)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->left = node->right = NULL;
    node->data =data;
    return node;
};


int isbst(struct node* root)
{
    return (isbstutil(root,INT_MIN,INT_MAX));
}

int isbstutil(struct node* root,int min,int max)
{
    if(root==NULL)
        return 1;

    if(root->data < min || root->data > max)
        return 0;

    return
      isbstutil(root->left,min,root->data-1)&&
      isbstutil(root->right,root->data+1,max);
}
