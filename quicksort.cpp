#include<bits/stdc++.h>
using namespace std;
int part(int arr[], int l, int h){
	int p= arr[h];
	int i=l-1;
	for (int j=l;j<=h;j++){
		if (arr[j]<=p){
			i++;
			swap(arr[j],arr[i]);
		}
	}
	return i;
}

void xqsort(int arr[], int l, int h){
	if (l<h){
		int pi= part(arr,l,h);
		xqsort(arr,l,pi-1);
		xqsort(arr,pi+1,h);
	}
}

int main(){

	int a[]={9,8,7,6,5,4,3};
	xqsort(a,0,6);
	for (int i=0;i<7;i++){
		cout<<a[i]<<' ';
	}
}