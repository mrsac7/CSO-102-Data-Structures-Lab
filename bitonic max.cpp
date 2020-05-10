#include<bits/stdc++.h>
using namespace std;

int bm (int arr[], int l, int h){
	while (l<=h){
		int m = (l+h)/2;

		if (arr[m-1]<arr[m] && arr[m]>arr[m+1])
			return m;

		if (arr[m-1]<arr[m] && arr[m]<arr[m+1]){
			l=m+1;
		}
		else h=m-1;
	}
	return -1;
}

int main(){
	int a[]={10,34,56,76,87,80,70,66,56,30,28,25,20,15,11};
	cout<<bm(a,0,14)<<' '<< a[bm(a,0,14)];
}