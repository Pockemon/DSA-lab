/*
   HARDIK RANA
   program to evaluate postfix expression using stack
*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int top=-1;
int stack[SIZE];
int is_operand(char ch);
int pop();
void push();

int main()
{
  char postfix[SIZE],ch;
  int op1,op2,result,m,i=0;
  printf("enter postfix expression\n");
  scanf("%s",postfix);
  while(postfix[i]!='\0')
  {
    ch=postfix[i];
    if(is_operand(ch)==1)
    {
    printf("enter the value of %c:",ch);
    scanf("%d",&m);
    push(m);
    }
   else
   {
      op2=pop();
      op1=pop();
      switch(ch)
      {
      case'+':
             result=op1+op2;
             push(result);
             break;
      case'-':
             result=op1-op2;
             push(result);
             break;
      case'*':
             result=op1*op2;
             push(result);
             break;
      case'/':
             result=op1/op2;
             push(result);
             break;
      case'%':
            result=op1%op2;
            push(result);
            break;
        }
     }
    i++;
  }
    result=pop();
    printf("the result of postfix expression is=%d",result);
    return 0;
 }

int is_operand(char ch)
{
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
    return 1;
    else
    return 0;
}

void push(int num)
{
    top++;
    stack[top]=num;
}
 
int pop()
{
    int a;
    a=stack[top];
    top--;
    return a;
}
