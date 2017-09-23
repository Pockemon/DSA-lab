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

void pop(){
      printf("%c",stack[top--]);
}


int main()
{
   char str[500];
   printf("enter the string\n");
   gets(str);
   int len = strlen(str);
   int i;

   for(i=0;i<len;i++)
        push(str[i]);
   printf("the reversed string is\n");
   for(i=0;i<len;i++)
      pop();
   return 0;
}
