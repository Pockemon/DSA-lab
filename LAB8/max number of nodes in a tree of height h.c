/*
   HARDIK RANA
   C program to maximun number of nodes in a binary tree of height h
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int H;
    printf("Enter the height of tree :");
    scanf("%d",&H);
    printf("Number of nodes : %d\n",(int)pow(2,H+1)-1);
    return 0;
}
