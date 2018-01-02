/*
  HARDIK RANA
  
  DSA SEM3-LAB 9
  
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct node
{
    char data;
    struct node *left,*right;
};

struct node *newNode(char x)
{
     struct node *ptr=(struct node*)malloc(sizeof(struct node));
     ptr->data=x;
     ptr->left=NULL;
     ptr->right=NULL;
     return ptr;
}

int Search(char in[],int start,int end,char key)
{
    int i;
    for(i=start;i<=end;i++)
    {
        if(in[i]==key)
            return i;
    }
}

struct node *buildTree(char post[],char in[],int first,int last,int *ptr)
{

       if(first>last)
          return NULL;

       struct node *new=newNode(post[*ptr]);
       *ptr=*ptr-1;

       if(first==last)
          return new;

       int indx=Search(in,first,last,new->data);

       new->right=buildTree(post,in,indx+1,last,ptr);
       new->left=buildTree(post,in,first,indx-1,ptr);

}

void Inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        Inorder(ptr->left);
        printf(" %c",ptr->data);
        Inorder(ptr->right);
    }
}

int main()
{
      char post[1000],in[1000];
      printf("Enter the inorder traversal :");
      scanf("%s",in);
      printf("Enter the postorder traversal :");
      scanf("%s",post);

      int ptr=strlen(in)-1;
      struct node *root=buildTree(post,in,0,strlen(in)-1,&ptr);

      printf("InOrder traversal of the constructed tree :");
      Inorder(root);

      return 0;
}
