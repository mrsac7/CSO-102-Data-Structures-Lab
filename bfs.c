#include<bits/stdc++.h>
using namespace std;

#define m 5

void bfs(int arr[][m],int node){
	queue<int> q;
	q.push(node);
	int vis[m]={0};
	vis[node]=1;
	while(!q.empty()){
		node=q.front();
		q.pop();
		printf("%c-",node+65);
		for (int i=0;i<m;i++){
			if (vis[i]==0 && arr[node][i]!=0){
				q.push(i);
				vis[i]=1;
			}
		}
	}
}


int main(){
	int mat[m][m];
	cout<<"\n Enter the adjacency matrix: \n";
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
    printf("BFS Traversal: ");
    bfs(mat,0);
}