#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 25

int top = -1;
int stack[MAX];

void push(char item)
{
      if(top == (MAX - 1))
      {
            printf("Stack is Full\n");
            return;
      }
      top++;
      stack[top] = item;
}

char pop()
{
      if(top == -1)
      {
            printf("Stack is Empty\n");
            exit(1);
      }
      return(stack[top--]);
}

int match_paranthesis(char a, char b)
{
      if(a == '[' && b == ']')
      {
            return 1;
      }
      else if(a == '{' && b == '}')
      {
            return 1;
      }
      else if(a == '(' && b == ')')
      {
            return 1;
      }
      return 0;
}

int check_paranthesis(char expression[])
{
      int i;
      char temp;
      for(i = 0; i< strlen(expression);i++)
      {
            if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            {
                  push(expression[i]);
            }
            if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
            {
                  if(top == -1)
                  {
                        printf("The Right Parentheses are more than the Left Parentheses\n");
                        return 0;
                  }
                  else
                  {
                        temp = pop();
                        if(!match_paranthesis(temp, expression[i]))
                        {
                              printf("The Mismatched Parentheses in the Expression are:\t%c and %c\n", temp, expression[i]);
                              return 0;
                        }
                  }
            }
      }
      if(top == -1)
      {
            printf("\nThe Expression has Balanced Parentheses\n");
            return 1;
      }
      else
      {
            printf("The Expression has unbalanced parentheses\n");
            return 0;
      }
}
int main()
{
      char expression[MAX];
      int c;
      printf("\nEnter an Expression:\t");
      scanf("%s", expression);
      c =check_paranthesis(expression);
      if(c== 1)
      {
            printf("The Expression is Valid\n");
      }
      else
      {
            printf("The Expression is Invalid\n");
      }
      return 0;
}
