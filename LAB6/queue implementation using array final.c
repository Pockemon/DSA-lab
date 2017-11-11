#include<stdio.h>
#include<conio.h>
#define max 50
void insert(int);
int del();
void display();
int queue[max];
int front=-1;
int rear=-1;
int main()
{
  int choice,num;
  while(1)
  {
    printf("enter your choice\n");
    printf("1.insert\n");
    printf("2.delete\n");
    printf("3.display\n");
    printf("4.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1:
           printf("enter number to be inserted\n");
           scanf("%d",&num);
           insert(num);
           break;
     case 2:
           num=del();
           break;
     case 3:
           display();
           break;
     case 4:
           exit(1);
     default:
            printf("invalid choice\n");
    }
  }
  return 0;
}
void insert(int element)
{
    if(rear==max-1)
        printf("queue is full\n");
    if(front==-1)
        front=0;
    rear=rear+1;
    queue[rear]=element;
}

int del()
{
  int element;
  if(front==-1 || front==rear+1)
  {
      printf("queue is empty\n");
      return;
  }
  element=queue[front];
  front=front+1;
  printf("%d has been deleted",element);
  return element;
}

void display()
{
 if(front==-1 ||front==rear+1)
 {
     printf("queue is empty\n");;
     return;
 }
 int i;
 for(i=front;i<=rear;i++)
 {
     printf("%d",queue[i]);
 }
}
