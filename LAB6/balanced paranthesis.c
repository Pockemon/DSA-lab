/*
  HARDIK RANA
  
  DSA SEM3-LAB 6
  
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack[200];
int top=-1;

int top1();
int is_paranthesis(char character);
int isempty();


int main()
{
  char para[50];
  int check,i;
  printf("enter the expression with paranthesis\n");
  scanf("%s",para);
  for(i=0;i<strlen(para);i++)
  {
      if(is_paranthesis(para[i]))
      {
          if(para[i] == '{' ||para[i] == '(' ||para[i] == '[')
          {
              push(para[i]);
              continue;
          }
          if(isempty())
             check=0;

          if(para[i]==')'&& top1()=='(')
            pop();
          else if(para[i]==']'&& top1()=='[')
            pop();
          else if(para[i]=='}'&& top1()=='{')
            pop();
          else
          {
              check=0;
              break;
          }
        }
      }
     if(check && isempty())
        printf("expression is balanced\n");
     else
        printf("expression is not balanced\n");
  }

void push(char ch)
{
    top++;
    stack[top]=ch;
}

int pop()
{
    top--;
}

int top1()
{
	return stack[top];
}

int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int is_paranthesis(char character)
{
	if(character=='(' || character==')' || character=='[' || character==']' || character=='{' || character=='}')
		return 1;
	else
		return 0;
}

