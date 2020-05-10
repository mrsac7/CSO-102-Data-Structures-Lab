#include<bits/stdc++.h>
using namespace std;

void heapify (int arr[], int n, int i){ //heapify down

	int l= 2*i +1;
	int r= 2*i +2;
	int m=i;
	if (l<n && arr[l]> arr[i])
		m=l;
	if (r<n && arr[r]> arr[m])
		m=r;
	if (m!=i){
		swap(arr[i],arr[m]);
		heapify(arr, n, m);
	}

}
void heapsort(int arr[], int n){

	for (int i= (n-2)/2; i>=0;i--)
		heapify(arr, n, i);

	for (int i=n-1; i>=0;i--){
		swap (arr[0],arr[i]);
		heapify(arr, i, 0);
	}

}

int main(){

	int arr[]={3,7,8,1,2,6,5};
	heapsort(arr, 7);
	for (int i=0; i<7;i++)
		cout<< arr[i]<<' ';

}