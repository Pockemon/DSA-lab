/*
  HARDIK RANA
  
  C PROGRAM TO EVALUATE PREFIX EXPRESSION USING STACK OPERATIONS 
*/

#include<stdio.h>
#include<string.h>
#define size 100

int is_operand(char ch);
void push();
int pop();
int stack[size];
int top=-1;

int main()
{
 char prefix[size],ch;
 int op1,op2,result,m,i;
 printf("enter prefix expression\n");
 scanf("%s",prefix);
 int len=strlen(prefix);
 for(i=len-1;i>=0;i--)
 {
  ch=prefix[i];
  if(is_operand(ch)==1)
  {
  printf("enter value of %c",ch);
  scanf("%d",&m);
  push(m);
  }
  else
  {
   op1=pop();
   op2=pop();
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
        }
     }
 }
    result=pop();
    printf("the result is=%d",result);
    return 0;
}

int is_operand(char ch)
{
 if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
 return 1;
 else
 return 0;
}

void push(int value)
{
 top++;
 stack[top]=value;
}

int pop()
{
 int a;
 a=stack[top];
 top--;
 return a;
}
