/*
   HARDIK RANA

   C PROGRAM TO IMPLEMENT QUEUE USING LINKED LIST
   
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
}*front=NULL,*rear=NULL;

void insert(int num);
int del();
void display();

int main()
{
  int choice, num;
  while(1)
  {
   printf("1 Insert\n");
   printf("2 Delete\n");
   printf("3 Display\n");
   printf("4 Exit\n");
   printf("Enter your choice\n");
   scanf("%d",&choice);
   switch(choice)
   {

    case 1:
         printf("Enter an element to insert ");
         scanf("%d",&num);
         insert(num);
          break;
    case 2:
          del();
          break;
    case 3:
         display();
         break;
    case 4:
         exit(1);
    default:
         printf("Wrong Input\n");

     }
   }
}


void insert(int num)
{
   struct node *temp;
   temp=(struct node *)malloc(sizeof(struct node));
   if(temp==NULL)
   {
      printf("Overflow\n");
      return;
   }
   temp->data=num;
   temp->next=NULL;
   if(front==NULL)
   {
    front=temp;
   }
   else
   {
    rear->next=temp;
    }
    rear=temp;
}

int del()
{
   int num;
   struct node *temp;
   if(front==NULL)
   {
      printf("Underflow\n");
      return;
    }
    temp=front;
    num=temp->data;
    front=front->next;
    free(temp);
    return num;
}

void display()
{
     struct node *p;
     if(front==NULL)
     {
        printf("Underflow\n");
        return;
      }
      p=front;
      printf("\nQueue Elements:\n");
      while(p!=NULL)
      {
        printf("%d ",p->data);
        p=p->next;
       }
 }
