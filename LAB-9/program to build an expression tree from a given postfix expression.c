/*
  HARDIK RANA
  
  DSA SEM3-LAB 9
  
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check(char ch);
struct node* pop();
void push(struct node* temp);
void inorder(struct node *temp);
void operand(char b);
void operators(char b);

struct node
{
    int data;
    struct node *left,*right;
};

int top=-1;
struct node *stack[20]; //STACK TREE TO STORE OPERAND AND OPERATORS

void main()
{
     char s[20];
     int p,i;
     printf("enter the postfix expressiobn\n");
     scanf("%s",s);
     int k = strlen(s);
     for(i=0;i<k;i++)
     {
         p=check(s[i]);
         if(p==1) //character is operand
            operand(s[i]);
         else if(p==2) //character is operator
            operators(s[i]);
     }
     int ans;
     ans=cal(stack[top]); //function to calculate value of postfix expresion
     printf("\nThe value of the postfix expression you entered is %d\n",ans);
     printf("\nThe inorder traversal of the tree is \n");
     inorder(stack[top]);
}

int check(char ch) //function to check if character at the top of the stack is operand or operator
{
    if(ch=='+' || ch=='-' || ch=='*' || ch== '/')
        return 2;
    else
        return 1;
}

void operand(char b) //if the character is operand then create a node with that operand and push it onto stack
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = b;
    temp->left = NULL;
    temp->right = NULL;
    push(temp);
}

void operators(char b) //if the character is operator then pop last two operands and make a new node of operand as last two oprands are its child
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = b;
  temp->right = pop();
  temp->left = pop();
  push(temp);
}

//calculating a value of prefix expression using recursion

int cal(struct node* temp)
{
    int ch;
    ch=check(temp->data);
    if(ch==1)
        return (temp->data-48);
    else if(ch==2)
    {
        if(temp->data=='+')
            return cal(temp->left)+cal(temp->right);

        if(temp->data=='-')
            return cal(temp->left)-cal(temp->right);

        if(temp->data=='*')
            return cal(temp->left)*cal(temp->right);

        if(temp->data=='/')
            return cal(temp->left)/cal(temp->right);

    }
}

void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
    inorder(temp->left);
    printf("%c",temp->data);
    inorder(temp->right);
    }
}

void push(struct node* temp)
{
    stack[++top]=temp;
}

struct node* pop()
{
    return(stack[top--]);
}
