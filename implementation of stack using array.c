#include<stdio.h>
#include<stdbool.h>
int top=-1;
int main()
{
 int n,stack[500],i,x,choice,y;
 char c;
 printf("enter size of stack array\n");
 scanf("%d",&n);
 do{
 printf("enter your choice(1)push (2)pop (3)size (4)top (5)display (6)exit\n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
    printf("enter the element to be inserted\n");
    scanf("%d",&x);
    push(stack,n,x);
    break;
  case 2:
    pop();
    break;
  case 3:
    y=size();
    printf("the size of stack is\n",size());
    break;
  case 4:
    printf("the top element of stack is\n",topelement());
    break;
  case 5:
     display(stack,top);
     break;
  case 6:
    exit(0);
    break;
 }printf("do u want to continue(y/n)\n");
 c=getchar();
 scanf("%c",&c);}
 while('y');
 return 0;
}
void display(int stack[],int top)
{
 int i;
 for(i=top;i>=0;i--)
 {
  printf("%d\t",stack[i]);
 }}

 void push(int stack[],int n,int x)
 {
  if(top==n-1)
  {
    printf("stack is full\n");
    return;
  }
  else
  {
    top=top+1;
    stack[top]=x;
  }
 }
 int pop(int top)
 {
  if(top==-1)
  {
   printf("stack is empty\n");
   return;
  }
  else
  {
    top=top-1;
  }}
  int size()
  {
    return top+1;
  }
  int topelement(int stack[])
  {
    return stack[top];
  }
