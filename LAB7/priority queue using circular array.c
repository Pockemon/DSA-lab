//Cicular Priority Queue

#include<stdio.h>

int Q[2][5],f=-1,r=-1;

void Enqueue(int x,int p)
{
    if(f==-1&&r==-1)
    {
        f=0;r=0;
        Q[0][f]=x;
        Q[1][f]=p;
        return ;
    }
    if((r+1)%5==f%5)
    {
        printf("Queue is Full");
        return ;
    }
    r=(r+1)%5;
    Q[0][r]=x;Q[1][r]=p;
    return ;
}

void Dequeue()
{
    int i;
    if(f==-1)
    {
        printf("Queue is Empty\n");
        return ;
    }
    if(f==r)
    {
        Q[0][f]=0;
        Q[1][f]=9999;
        f=-1;r=-1;
        return ;
    }
    int ptr=Q[1][0],temp=0;
    for(i=1;i<5;i++)
    {
        if(Q[1][i]<ptr)
        {
            ptr=Q[1][i];
            temp=i;
        }
    }

    // printf("@@%d %d\n",ptr,f);

    int data=Q[0][temp];
    int pri=Q[1][temp];
    Q[0][temp]=Q[0][f];
    Q[1][temp]=Q[1][f];
    Q[0][f]=data;
    Q[1][f]=pri;
    Q[0][f]=0;
    Q[1][f]=9999;
    f=(f+1)%5;
}

void display()
{
    int i=0;
    printf("|");
    for(i=0;i<5;i++)
        printf(" (%d , %d ) |",Q[0][i],Q[1][i]);
    printf("\n");
}

int main()
{
    int i,x,p,c;
    for(i=0;i<5;i++)
    {
        Q[1][i]=9999;
    }
    printf("1]Enqueue\n2]Dequeue3]Display\n4]Exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                   printf("Enter the element and priority want to insert:");
                   scanf("%d %d",&x,&p);
                   Enqueue(x,p);
                   break;
            case 2:
                   Dequeue();
                   break;
            case 3:
                   display();
                   break;
            case 4:
                   exit(1);
        }
    }

}
