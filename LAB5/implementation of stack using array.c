/* HARDIK RANA
  
   C PROGRAM TO IMPLEMENT STACK USING ARRAY
*/

#include<stdio.h>
#include<stdbool.h>

int top=-1;   //top of the stack
void display(int stack[],int top);
int size();
int topelement(int stack[]);
int pop();
 void push(int stack[],int n,int x);


int main()
{
 int n,stack[500],i,x,choice,y;
 char c;
 printf("enter size of stack array\n");
 scanf("%d",&n);
 
 while(1)
 {
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
      printf("the size of stack is=%d\n",size());
      break;
   
   case 4:
     printf("the top element of stack is=%d\n",topelement(stack));
     break;
   
   case 5:
      display(stack,top);
       break;
   
   case 6:
     exit(0);
     break;
   }
 }
  return 0;
}

//to display the content of stack
void display(int stack[],int top)
{
  int i;
  for(i=top;i>=0;i--)
  {
   printf("%d ",stack[i]);
  }
 printf("\n");
}

//to push the element into the stack
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

//to pop the top element
int pop()
 {
   if(top==-1)
   {
    printf("stack is empty\n");
    return;
   }
   else
   {
     top=top-1;
   }
 }

//to get the size of stack
int size()
  {
    return top+1;
  }

//to get the top element of stack
  int topelement(int stack[])
  {
    return stack[top];
  }
