#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 100

int top=-1;
char stack[size]; //stack to hold operators and operands
struct node* stack1[20]; //stack to hold values of node
int is_operator(char symbol);
char pop();
void push(char item);
int precendence(char symbol);
void inorder(struct node *temp);
void push1(struct node* temp);
struct node* pop1();
int cal(struct node* temp);
int check(char ch);
void operators(char b);
void operand(char b);


struct node
{
    int data;
    struct node *left,*right;
};



int main()
{
  char infix[size],postfix[size],item;
  int m;
  char temp;
  int i=0,j=0;
  printf("enter infix expression\n");
  gets(infix);
  //infix to postfix conversion
  while(infix[i]!='\0')
  {
     item=infix[i];
     if(item=='(')
     {
          push(item);
     }
      else if(item>='a'&& item<='z')
     {
        postfix[j]=item;
        j++;
     }
    else if(is_operator(item)==1)
    {
       temp=pop();
       while(is_operator(temp)==1 && precendence(temp)>=precendence(item))
      {
        postfix[j]=temp;
        j++;
        temp=pop();
       }
       push(temp);
       push(item);
   }
   else if(item==')')
   {
      temp=pop();
      while(temp!='(')
      {
        postfix[j]=temp;
        j++;
        temp=pop();
      }
    }
   i++;
  }
  while(top>-1)
  {
     postfix[j]=pop();
     j++;
   }
   postfix[j]='\0';
   printf("postfix expression is\n");
   printf("%s",postfix);
   //postfix expresion to expression tree
   int p;
   int k = strlen(postfix);
   for(i=0;i<k;i++)
   {
     p=check(postfix[i]);
     if(p==1) //character is operand
        operand(postfix[i]);
     else if(p==2) //character is operator
        operators(postfix[i]);
    }
    int ans;
    printf("\nThe inorder traversal of the tree is \n");
    inorder(stack1[top]);
    printf("\nThe preorder traversal of the tree is \n");
    preorder(stack1[top]);
    printf("\nThe postorder traversal of the tree is \n");
    postorder(stack1[top]);
}


void push(char item) //push in normal stack
  {
    if(top>=size-1)
    printf("stack overfloaw\n");
    else
    {
     top++;
     stack[top]=item;
    }
  }


int is_operator(char symbol)
  {
    if(symbol=='^'||symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
        return 1;
    else
        return 0;
  }


char pop() //pop in normal stack
 {
    char item;
    item=stack[top];
    top--;
    return item;
  }

int precendence(char symbol) //to check precendence
{
    if(symbol=='^')
       return 3;
    else if(symbol=='/'||symbol=='*')
       return 2;
    else if(symbol=='+'||symbol=='-')
        return 1;
    else
        return 0;

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
    push1(temp);
}

void operators(char b) //if the character is operator then pop last two operands and make a new node of operand as last two oprands are its child
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = b;
  temp->right = pop1();
  temp->left = pop1();
  push1(temp);
}

//calculating a value of prefix expression using recursion


void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
    inorder(temp->left);
    printf("%c",temp->data);
    inorder(temp->right);
    }
}

void preorder(struct node *temp) //preorder traversal
{
  if(temp!=NULL)
  {
    printf("%c",temp->data);
    preorder(temp->left);
    preorder(temp->right);
  }
}

void postorder(struct node *temp) //postorder traversal
{
  if(temp!=NULL)
  {
    postorder(temp->left);
    postorder(temp->right);
    printf("%c",temp->data);
  }
}

void push1(struct node* temp) //push in tree stack
{
    stack1[++top]=temp;
}

struct node* pop1() //pop in tree stack
{
    return(stack1[top--]);
}

