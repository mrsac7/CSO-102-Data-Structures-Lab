#include<bits/stdc++.h>
using namespace std;
#define n 6

int m[n][n]={0};
int vis[n]={0};
stack<int> s;
void dfs(int i){
	vis[i]=1;
	for (int j=0;j<n;j++){
		if (m[i][j] && !vis[j]){
			dfs(j);
		}
	}
	s.push(i);
}

int main(){

	for (int k=0;k<n;k++){
		int i,j;
		cin>>i>>j;
		m[i][j]=1;
	}
	for (int i=0;i<n;i++){
		if (!vis[i])dfs(i);
	}
	for (int i=0;i<n;i++){
		cout<< s.top()<<' ';
		s.pop();
	}
}