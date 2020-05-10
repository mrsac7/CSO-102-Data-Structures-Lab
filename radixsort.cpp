#include<bits/stdc++.h>
using namespace std;
void countsort(int arr[], int n, int exp){
	int count[10] = {0}; 
	for (int i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 
 
	for (int i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	int output[n];
	for (int i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 

	for (int i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

void radixsort(int arr[],int n){

	int m=arr[0];
	for (int i=0;i<n;i++){
		if (m<arr[i]) m=arr[i];
	}

	for (int exp=1; m/exp>0;exp*=10){
		countsort(arr, n, exp);
	}
}

int main(){
	int a[]={170, 45, 75, 90, 802, 24, 2, 66};
	radixsort(a, 8);
	for (int i=0; i<8;i++)
		cout<<a[i]<< ' ';
}