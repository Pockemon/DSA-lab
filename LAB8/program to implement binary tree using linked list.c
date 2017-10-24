#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(struct node *root,int x)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=x;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

void print(struct node *root)
{
    if(root==NULL)
    return;
    printf("%d\n",root->data);
    print(root->left);
    print(root->right);
}

void delete(struct node **root)
{
    if(*root==NULL)
    {
         printf("tree is empty so can't delete\n");
         return;
    }
    if((*root)->left)
        delete(&((*root)->left));
    if((*root)->right)
        delete(&((*root)->right));
    free(*root);
}

int search(struct node *root,int x)
{
    if(root==NULL)
        return 0;
    if(root->data==x)
        return 1;
    if(search(root->left,x)==1)
        return 1;
    if(search(root->right,x)==1)
        return 1;

}

void main()
{
    struct node *root=NULL;
    struct node *present=NULL,*prev;
    char ch;
    int choice,x,c,d,cc,dd,h,hh,hi;
    do
    {
        printf("Enter choice 1. to insert 2. to delete 3. to print 4. to search\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                     c=0;
                     while(c==0)
                     {
                         printf("Enter no. to be inserted\n");
                         scanf("%d",&x);
                         if(root==NULL)
                         {
                              root=create(root,x);
                              present=root;
                              c=1;
                         }
                         else
                         {
                              present=root;
                              while(c==0)
                              {
                                   printf("Do you want to insert in left(1) or right(2)?\n");

                                   scanf("%d",&d);
                                   if(d==1)
                                   {

                                        if(present->left==NULL)
                                        {
                                             present->left=create(root,x);
                                             c=1;
                                        }
                                        else
                                        {
                                             present=present->left;
                                        }
                                   }
                                   else if(d==2)
                                   {
                                        if(present->right==NULL)
                                        {
                                             present->right=create(root,x);
                                             c=1;
                                        }
                                        else
                                        {
                                             present=present->right;
                                        }
                                   }
                              }
                         }
                     }
            break;
            case 2:
                     c=0;
                     present=root;
                     printf("1.to delete root node 2.to continue\n");
                     scanf("%d",&hh);
                     if(hh==1)
                     {
                          delete(&present);
                          root=NULL;
                          c=1;
                     }
                     while(c==0 && ((present)->left!=NULL || (present)->right!=NULL))
                     {
                          printf("1.for left 2.for right\n");
                          scanf("%d",&cc);
                          if(cc==1)
                          {
                              prev=present;
                              present=present->left;
                              printf("1.to delete 2.to continue\n");
                              scanf("%d",&h);
                              if(h==1)
                              {
                                   delete(&present);
                                   prev->left=NULL;
                                   c=1;
                              }
                          }
                          else if(cc==2)
                          {
                              prev=present;
                              present=present->right;
                              printf("1.to delete 2.to continue\n");
                              scanf("%d",&h);
                              if(h==1)
                              {
                                   delete(&present);
                                   prev->right=NULL;
                                   c=1;
                              }
                          }
                     }
            break;
            case 3:
                     print(root);
            break;
            case 4:
                     printf("Enter no. to be searched\n");
                     scanf("%d",&x);
                     hi=search(root,x);
                     if(hi==1)
                          printf("Element found in tree\n");
                     else
                          printf("Element not found in tree\n");
            break;
            default:
                     printf("Invalid chioce\n");
            break;
        }
        printf("Do you want ot continue?('y' or 'n')\n");
        getchar();
        ch=getchar();
    }while(ch=='y');
}
