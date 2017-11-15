/*

   HARDIK RANA

   DEPTH FIRST TRAVERSAL OF GRAPH

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


void recursive_DFS(int k);
void insert(node1,node2);
struct node *newnode(int data);


int main()
{
    int n,i,e;
    int nodea,nodeb;
    printf("enter number of nodes and edges\n");
    scanf("%d %d",&n,&e);
    for(i=0;i<e;i++)
    {
        scanf("%d %d",&nodea,&nodeb);
        insert(nodea,nodeb);
        insert(nodeb,nodea);  //for undirected
    }
    printf("graph representation\n");
    for(i=1;i<=n;i++)
    {
        printf("%d :",i);
        struct node *temp=adj[i];
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    int k;
    printf("enter starting vertex for dfs\n");
    scanf("%d",&k);
    printf("DFS\n");
    recursive_DFS(k);
    return 0;
}

//to add edge between two vertex
void insert(node1,node2)
{
    struct node *temp1,*temp2;
    temp2=newnode(node2);
    if(adj[node1]==NULL)
    {
        adj[node1]=temp2;
    }
    else
    {
        struct node *temp1=adj[node1];
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp2;
    }
}

//to create new node
struct node *newnode(int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

//recursive dfs
void recursive_DFS(int k)
{
    visited[k]=true;
    printf("%d ",k);
    struct node *temp=adj[k];
    while(temp!=NULL)
    {
        if(!visited[temp->data])
            recursive_DFS(temp->data);
        temp=temp->next;
    }
}
