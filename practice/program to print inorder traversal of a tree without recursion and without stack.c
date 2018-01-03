/*
  HARDIK RANA
  
  DSA SEM3
  
*/

//algorithm
/*
1. Initialize current as root
2. While current is not NULL
   If current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as right child of the rightmost
         node in current's left subtree
      b) Go to this left child, i.e., current = current->left
*/

#include<stdio.h>
#include<stdlib.h>
struct node *newnode(int data);

struct node
{
    int data;
    struct node *left,*right;
};

int main()
{
    struct node *root= newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);

    traversal(root);
    return 0;

}


struct node *newnode(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = new->right =NULL;
}

void traversal(struct node *root)
{
    struct node *current = root,*pre;

    if(root == NULL)
        return;

    while(current != NULL)
    {
        if(current->left == NULL)
        {
            printf("%d ",current->data);
            current = current->right;
        }

        else
        {
          pre = current->left;
          while(pre->right !=NULL && pre->right != current)
                pre = pre->right;

          if(pre->right == NULL)
          {
              pre->right = current;
              current = current->left;
          }

          else
          {
              pre->right = NULL;
              printf("%d ",current->data);
              current = current->right;
          }
        }
    }
}
