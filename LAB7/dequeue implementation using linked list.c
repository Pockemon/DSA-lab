/*
  HARDIK RANA
  
  DSA SEM3-LAB 7
  
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int info;
 struct node *next;
}*front,*temp,*rear,*ptr;
void insertr()
{
 temp=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter elemet: ");
 scanf("%d",&temp->info);
 temp->next=NULL;
 if(front==NULL && rear==NULL)
 {
  front=rear=temp;
  return;
 }
 rear->next=temp;
 rear=rear->next;
}
void delf()
{
 if(front==NULL)
 {
  printf("\nEmpty Deque\n");
  return;
 }
 if(front==rear && front!=NULL)
 {
  ptr=front;
  front=rear=NULL;
  free(ptr);
 }
 else
 {
  ptr=front;
  front=front->next;
  free(ptr);
 }
}
void insertf()
{
 temp=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter element: ");
 scanf("%d",&temp->info);
 if(front==NULL && rear==NULL)
 {
  front=rear=temp;
  temp->next=NULL;
  return;
 }
 temp->next=front;
 front=temp;
}
void delr()
{
 if(rear==front && rear==NULL)
 {
  printf("Empty DEQUE");
  return;
 }
 else if(rear==front)
 {
  rear=front=NULL;
  free(rear);
  free(front);
 }
 else
 {
  ptr=front;
  while(ptr->next!=NULL)
  {
   temp=ptr;
   ptr=ptr->next;
  }
  temp->next=NULL;
  free(ptr);
  rear=temp;
 }
}
void show()
{
 if(front==NULL && rear==NULL)
 {
  printf("\nEmpty Deque\n");
  return;
 }
 ptr=front;
 while(ptr!=NULL)
 {
  printf("%d\t",ptr->info);
  ptr=ptr->next;
 }
}
void main()
{
 int ch;
 while(1)
 {
  printf("\n1. Insert at rear");
  printf("\n2. Insert at Front");
  printf("\n3. Delete from front");
  printf("\n4. Delete from rear");
  printf("\n5. Show");
  printf("\n6. Exit");
  printf("\nEnter ur choice: ");
  scanf("%d",&ch);
  switch (ch)
  {
   case 1: insertr(); break;
   case 2: insertf(); break;
   case 3: delf(); break;
   case 4: delr(); break;
   case 5: show(); break;
   case 6: exit(0); break;
   default: printf("Invalid option");
  }
 }
}
