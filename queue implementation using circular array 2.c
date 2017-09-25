#include<stdio.h>

int Q[5],front=-1,rear=-1;

void Enqueue(int x)
{
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        Q[rear]=x;
        return ;
    }
    if((rear+1)%5==front)
    {
        printf("Queue is full\n");
        return ;
    }
    else
    {
        rear=(rear+1)%5;
        Q[rear]=x;
    }
    return ;
}

void Dequeue()
{
    if(front==-1)
    {
        printf("Queue is Empty\n");
        return ;
    }
    if(front==rear)
    {
        Q[front]=0;
        front=-1;
        rear=-1;
        return ;
    }
    Q[front]=0;
    front=(front+1)%5;
    return ;
}

void Display()
{
    int i;
    printf("|");
    for(i=0;i<5;i++)
        printf(" %d |",Q[i]);
    printf("\n");
}

int main()
{
    int x,c;
    printf("1]Insert\n2]Delete\n3]Display\n4]Exit\n");
    while(1)
    {
        printf("Enter the choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                  printf("Enter the element want to Insert:");
                  scanf("%d",&x);
                  Enqueue(x);
                  break;
            case 2:
                  Dequeue();
                  break;
            case 3:
                  Display();
                  break;
            case 4:
                  exit(1);
        }
    }
}
