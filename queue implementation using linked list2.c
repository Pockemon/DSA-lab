#include<stdio.h>
#include<stdlib.h>
struct node{
       int info;
       struct node *link;
       }*front=NULL,*rear=NULL;

       void insert(int num);
       int del();
       void display();

       main()
       {
             int choice, num;
             while(1)
             {
             printf("\n1 Insert\n");
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
     temp->info=num;
     temp->link=NULL;
     if(front==NULL)
      {
       front=temp;
      }
     else
      {
      rear->link=temp;
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
          num=temp->info;
          front=front->link;
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
                                         printf("%d ",p->info);
                                         p=p->link;
                         }

     }
