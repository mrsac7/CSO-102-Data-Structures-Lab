#include<stdio.h>
#define MAX 50
#include<stdlib.h>
#include<iostream>
using namespace std;
int n,a[MAX][MAX],visited[MAX],i,j,f=0,r=-1,q[MAX*100],top=0,stack[MAX+1];
#define dfs DFS
void DFS(int i)
{
    int j;
    
    visited[i]=1;
    
    for(j=1;j<=n;j++)
       if(!visited[j]&&a[i][j]==1)
            DFS(j);
    stack[top++]=i;
}

int main()
{
    int v;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
        {q[i]=0;visited[i]=0;}
    printf("Enter the number of edges:");
    for(i=1;i<=n;i++)
        {for(j=1;j<=n;j++)
            a[i][j]=0;}
    int ne=0;
    cin>>ne;
    cout<<"Enter u,v:\n";
    for(i=0;i<ne;i++)
    {
        int tt,tt2;
        cin>>tt>>tt2;
        a[tt][tt2]=1;
    }
    for(i=1;i<=n;i++)
        if(!visited[i]) dfs(i);
    while(top--){
        cout<<stack[top]<<" ";
    }

}