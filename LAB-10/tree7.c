/*
 HARDIK RANA 
 program to implement binary search tree
 1]Insert\n2]Delete\n3]Search the element and print the path\n4]Find maximum and minimum

*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

int path[1000];

struct node *getNode(int x)
{
       struct node *temp=(struct node*)malloc(sizeof(struct node));
       temp->data=x;
       temp->left=NULL;
       temp->right=NULL;
       return temp;
}

void Insert(int x,struct node **root)
{
   struct node *temp=*root,*prev=root;
   if(*root==NULL)
   {
       *root=getNode(x);
   }
   else
   {
       while(temp!=NULL)
       {
           if(x<temp->data)
           {
                prev=temp;
                temp=temp->left;
           }
           else
           {
               prev=temp;
               temp=temp->right;
           }
       }
       temp=getNode(x);
       if(x<prev->data)
       {
           prev->left=temp;
       }
       else
       {
           prev->right=temp;
       }


   }
}

void print_min_max(struct node *root)
{
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return ;
    }

    struct node *temp=root;

    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    printf("Minimum = %d\n",temp->data);

    while(root->right!=NULL)
    {
        root=root->right;
    }

    printf("Maximum = %d\n",root->data);

    return ;
}

void print(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        print(temp->left);
        print(temp->right);
    }
}

void print_data(int indx)
{
    int i;
    if(indx)
    {
        printf("Element Found!!!!\nPath :");
        for(i=0;i<indx;i++)
           printf("%d ",path[i]);
    }
    else
        printf("Element found and it's root");
    printf("\n");
    return ;
}

void search_and_print(struct node *root,int indx,int key)
{
    if(root->data==key)
    {
        print_data(indx);
        return ;
    }

    if(key<root->data&&root->left!=NULL)
    {
        path[indx]=root->data;
        search_and_print(root->left,++indx,key);
    }
    else if(key>=root->data&&root->right!=NULL)
    {
        path[indx]=root->data;
        search_and_print(root->right,++indx,key);
    }

    if(root->left==NULL||root->right==NULL)
    {
        printf("Element not found\n");
        return ;
    }

}

struct node *minValue(struct node* root)
{
    struct node *ptr=root;

    while (ptr->left != NULL)
        ptr=ptr->left;

    return ptr;
}

struct node* Delete(struct node* root, int key)
{
    if (root==NULL)
        return root;

    if (key < root->data)
        root->left=Delete(root->left, key);

    else if (key > root->data)
        root->right=Delete(root->right, key);

    else
    {
        if (root->left==NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValue(root->right);

        root->data= temp->data;

        root->right = Delete(root->right, temp->data);
    }
    return root;
}

int main()
{
    int x,c;
    struct node *root=NULL;
    printf("1]Insert\n2]Delete\n3]Search the element and print the path\n4]Find maximum and minimum\n5]Exit\n");
    while(1)
    {
        printf("\nEnter your choice :");
        scanf("%d",&c);
        switch(c)
        {
           case 1:
                 printf("Enter the element :");
                 scanf("%d",&x);
                 Insert(x,&root);
                 break;
           case 2:
                 printf("Enter the element want to delete:");
                 scanf("%d",&x);
                 Delete(root,x);
                 break;
           case 3:
                 printf("Enter the element want to search :");
                 scanf("%d",&x);
                 search_and_print(root,0,x);
                 break;
           case 4:
                 print_min_max(root);
                 break;
           case 5:
                exit(1);
        }
    }
    return 0;
}
