#include<stdio.h>
#define MAX 999999
#define MIN -999999
int g[1000][1000],d[1000],pi[1000],visited[1000];

int getMin(int n)
{
     int i=0,j,min=MAX;
     for(i=0;i<n;i++)
     {
         if(visited[i]==0 && d[i]<=min)
         {
             min=d[i];
             j=i;
         }
     }
     return j;
}

void main()
{
     int e,n;
     printf("Enter no. of nodes & edges\n");
     scanf("%d %d",&n,&e);
     int j,src,i,u,v,w;
     for(i=0;i<e;i++)
     {
          printf("Enter edge from & to & weight\n");
          scanf("%d %d %d",&u,&v,&w);
          g[u][v]=w;
          g[v][u]=w;
     }

     for(i=0;i<n;i++)
     {
          d[i]=MAX;
          pi[i]=-1;
     }

     printf("Enter source vertex\n");
     scanf("%d",&src);
     d[src]=0;
     pi[src]=-1;

     for(i=0;i<n-1;i++)
     {
          u=getMin(n);
          visited[u]=1;

          for(j=0;j<n;j++)
          {
              if(g[u][j] && visited[j]==0 && d[u]!=MAX && (d[u]+g[u][j])<d[j])
              {
                   d[j]=d[u]+g[u][j];
                   pi[j]=u;
              }
          }
     }

     for(i=0;i<n;i++)
     {
         printf("%d->%d\n",i,d[i]);
     }
}
