#include<stdio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node* next;
};
struct Node *top=NULL;
void push(int num);
int pop();
void display();
int main()
{
 int choice,num;
 while(1)
 {
  printf("\n 1 push\n");
  printf("2 pop\n");
  printf("3 display\n");
  printf("4 exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
       printf("enter number to be inserted\n");
       scanf("%d",&num);
       push(num);
       break;
   case 2:
       num=pop();
       break;
   case 3:
       display();
       break;
   case 4:
       exit(1);
   default:
       printf("invalid input\n");
  }}}
void push(int num)
{
 struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
 if(temp==NULL)
 {
  printf("stack overflow\n");
  return;
 }
 temp->data=num;
 temp->next=top;
 top=temp;
}
int pop()
{
  struct Node *temp;
  int num;
  if(top==NULL)
  {
   printf("underflow\n");
   return;
  }
  temp=top;
  num=top->data;
  top=top->next;
  free(temp);
  printf("the deleted number is=%d",num);
  return num;
}
void display()
{
  struct Node *p;
  if(top==NULL)
  {
    printf("stack underflow\n");
    return;
  }
  printf("\n stack is:\n");
  p=top;
  while(p!=NULL)
  {
   printf("%d\n",p->data);
   p=p->next;
  }
}
