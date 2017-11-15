/*
    HARDIK RANA

	Depth First Search using Adjacency List-Iterative
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
}*adj[1000];

bool visited[100];
int stack[1000],top=-1;

void stack_push(int element)
{
    if(top==999)
    {
        printf("Stack is full\n");
        return;
    }
    ++top;
    stack[top]=element;

}

void stack_pop()
{
    if(top==-1)
    {
        printf("Stack empty\n");
        return;
    }
    top--;
}

int stack_top()
{
    return stack[top];
}

bool isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}

struct node *newNode(int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void insert(int node1,int node2)
{
    struct node *temp1,*temp2;
    temp2=newNode(node2);
    if(adj[node1]==NULL)
    {
        adj[node1]=temp2;
    }
    else
    {
        temp1=adj[node1];
        while(temp1->next!=NULL)
            temp1=temp1->next;
        temp1->next=temp2;
    }
    return ;
}

int main()
{
    int n,e,node1,node2,i;
    printf("Enter the number of nodes and edges:- ");
    scanf("%d %d",&n,&e);
    for(i=0;i<e;i++)
    {
        printf("Enter the edges: ");
        scanf("%d %d",&node1,&node2);
        insert(node1,node2);
        insert(node2,node1);
    }

    printf("Graph representation:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d : ",i);
        struct node *temp=adj[i];
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

     int element;
    printf("Enter the node from which you want DFS: ");
    scanf("%d",&element);
    printf("DFS of graph :\n");
    iterative_DFS(element);
    return 0;

    return 0;
}


void iterative_DFS(int node)
{
    stack_push(node);
    visited[node]=true;
    printf("%d ", node);
    while(!isEmpty())
    {
        int num=stack_top();
        stack_pop();
        struct node *temp=adj[num];
        while(temp!=NULL)
        {
            if(!visited[temp->data])
            {
                stack_push(temp->data);
                printf("%d ",temp->data);
                visited[temp->data]=true;
            }
            temp=temp->next;
        }
    }
}
