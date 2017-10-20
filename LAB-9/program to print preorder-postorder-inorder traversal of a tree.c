//program to find inorder/preorder/postorder traversal of a a tree

#include<stdio.h>

int tree[12345];

void insert(int x,int root)
{
 if(tree[root]==0)
 {
  tree[root]=x;
  return;
 }
  int c;
  printf("press 1 to insert to left and 2 to insert to right\n");
  scanf("%d",&c);
  if(c==1)
      insert(x,2*root);
  else if(c==2)
      insert(x,2*root+1);
 }

void preorder(int root)
{
  if(tree[root]!=0)
  {
    printf("%d",tree[root]);
    preorder(2*root);
    preorder(2*root+1);
  }
}
void inorder(int root)
{
  if(tree[root]!=0)
  {
    inorder(2*root);
    printf("%d",tree[root]);
    inorder(2*root+1);
  }
}

void postorder(int root)
{
  if(tree[root]!=0)
  {
    postorder(2*root);
    postorder(2*root+1);
    printf("%d",tree[root]);
  }
}




int main()
{
   printf("\n1]insert\n2]inorder\n3]preorder\n4]postorder\n5]exit\n");
   int x,c;
   while(1)
   {
    printf("\nenter your choice\n");
    scanf("%d",&c);
    switch(c)
    {
     case 1:
           printf("enter the element u want to insert\n");
           scanf("%d",&x);
           insert(x,1);
           break;
     case 2:
           printf("inorder\n");
           inorder(1);
           break;
     case 3:
           printf("preorder\n");
           preorder(1);
           break;
     case 4:
           printf("postorder\n");
           postorder(1);
           break;
    case 5:
           exit(1);
   }
   }
 }

