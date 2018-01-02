/*
  HARDIK RANA
  
  DSA SEM3-LAB 7
  
*/

#include <stdio.h>
#include <string.h>

#define max 100
int top,stack[max];

void push(char x){

      if(top == max-1){
          printf("stack overflow");
      }  else {
          stack[++top]=x;
      }

}

int main()
{
   char str[500],revstr[500];
   int c;
   printf("enter the string\n");
   gets(str);
   int len = strlen(str);
   int i;

   for(i=0;i<len;i++)
        push(str[i]);
   printf("the reverses string is\n");
   for(i=0;i<len;i++)
      revstr[i]=stack[top--];
   c=strcmp(str,revstr);
   if(c==0)
    printf("pallindrome\n");
   else
    printf("not pallindrome\n");
   return 0;
}
