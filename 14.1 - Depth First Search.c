#include<bits/stdc++.h>
using namespace std;

#define m 5

void dfs(int arr[][m],int node){
	stack<int> s;
	s.push(node);
	int vis[m]={0};
	vis[node]=1;
	while(!s.empty()){
		node=s.top();
		s.pop();
		printf("%c-",node+65);
		for (int i=0;i<m;i++){
			if (arr[node][i]!=0 && vis[i]==0){
				s.push(i);
				vis[i]=1;
			}
		}
	}

}

int main(){
	int mat[m][m];
	cout<<"\nEnter the adjacency matrix: \n";
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
    printf("DFS Traversal: ");
    dfs(mat,0);

}

