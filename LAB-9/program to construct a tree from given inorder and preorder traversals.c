/*
  HARDIK RANA
  
  DSA SEM3-LAB 9
  
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* buildtree(char in[],char pre[],int instr,int inend);
struct node* newnode(char data);
int search(char arr[],int strt,int end,char value);
void printInorder(struct node* node);

int main()
{
    char pre[100],in[100];
    printf("enter an inorder traversal\n");
    scanf("%s",in);
    printf("enter an preorder traversal\n");
    scanf("%s",pre);
    int len=strlen(in);

    struct node *root = buildtree(in,pre,0,len-1);

    printf("inorder traversal of a constructed tree is\n");
    printInorder(root);
    return 0;
}

struct node* buildtree(char in[],char pre[],int instr,int inend) //FUNCTION TO BUILD A TREE
{
    static int preindex=0;

    if(instr>inend)
        return NULL;

    struct node *tnode = newnode(pre[preindex++]); //MAKE NEW NODE WITH FIRST ELEMENT OF PREORDER TRAVERSAL AND INCREMENT PREORDER INDEX

    if(instr == inend)
        return tnode;

    int inindex = search(in,instr,inend,tnode->data); //SERACH INDEX OF DATA THAT IS FIRST IN PREORDER TRAVERSAL

    tnode->left = buildtree(in,pre,instr,inindex-1);//RECURSIVELY CALL BUILDTREE FUNCTION FOR LEFT AND RIGHT SUBTREES OF DATA
    tnode->right = buildtree(in,pre,inindex+1,inend);

    return tnode;
}

struct node* newnode(char data) //TO CREATE NEW NODE
{
  struct node* new=(struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->left = new->right = NULL;
  return(new);
}

int search(char arr[],int strt,int end,char value) //FUNCTION TO SEARCH INDEX
{
    int i;
    for(i=strt;i<=end;i++)
    {
        if(arr[i]==value)
            return i;
    }
}

void printInorder(struct node* node)
{
  if (node == NULL)
     return;

  printInorder(node->left);

  printf("%c ", node->data);

  printInorder(node->right);
}
