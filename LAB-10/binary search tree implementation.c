/*
 HARDIK RANA 
 program to implement binary search tree
 1]Insert 2]Delete 3]Search the element and print the path  4]Find maximum and minimum 5]print inorder
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node *root,int x);
struct node *newnode(int data);
struct node *delete_node(struct node *root,int data);
struct node * minValueNode(struct node* node);
void inorder(struct node *root);

int path[100];

int main()
{
    int x,c;
    struct node *root=NULL;
    while(1)
    {
    printf("Enter\n1]insert\n2]delete\n3]search the element and print the path\n4]find maximum and minimum\n5]to display inorder traversal\n6]exit\n");
    printf("\nEnter your choice :");
    scanf("%d",&c);
    switch(c)
    {
      case 1:
             printf("Enter the element :");
             scanf("%d",&x);
             root=insert(root,x);
             break;
      case 2:
             printf("Enter the element want to delete:");
             scanf("%d",&x);
             root=delete_node(root,x);
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
                printf("Inorder traversal\n");
				inorder(root);
				printf("\n");
				break;

		case 6:
                exit(1);
        }
   }
    return 0;
}

struct node* insert(struct node *root,int x)
{
   if(root==NULL)
     return newnode(x);

   if(x<root->data)
      root->left=insert(root->left,x);

   else if(x>root->data)
      root->right=insert(root->right,x);

   return root;
}

struct node *newnode(int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

struct node *delete_node(struct node *root,int data)
{
 if(root==NULL)return root;
 if(data< root->data)
    root->left = delete_node(root->left,data);

 else if(data>root->data)
    root->right=delete_node(root->right,data);

 else
 {
     //node with only one or no child
     if(root->left==NULL)
     {
         struct node *temp=root->right;
         free(root);
         return temp;
     }
     else if(root->right == NULL)
     {
         struct node *temp=root->left;
         free(root);
         return temp;
     }

     struct node* temp=minValueNode(root->right);
     root->data = temp->data;
     root->right = delete_node(root->right,temp->data);
 }
 return root;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void print_min_max(struct node *root)
{
    struct node *ptr=root;
    while(ptr->left !=NULL)
        ptr=ptr->left;
    printf("minimum value=%d\n",ptr->data);
    ptr=root;
    while(ptr->right !=NULL)
        ptr=ptr->right;
    printf("Maximum value=%d\n",ptr->data);
}

void search_and_print(struct node *root,int index,int data)
{
    if(root->data == data)
    {
        print_data(index);
        return;
    }
    if(data<root->data && root->left !=NULL)
    {
        path[index]=root->data;
        search_and_print(root->left,++index,data);
    }

    else if(data>root->data && root->right !=NULL)
    {
        path[index]=root->data;
        search_and_print(root->right,++index,data);
    }

    if(root->left ==NULL || root->right ==NULL)
    {
        printf("element not found\n");
        return;
    }
}

void print_data(int index)
{
    int i;
    if(index)
    {
        printf("Element Found!!!!\nPath :");
        for(i=0;i<index;i++)
           printf("%d ",path[i]);
    }
    else
        printf("Element found and it's root");
    printf("\n");
    return ;
}
