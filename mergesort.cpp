#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r){

	int n1= m-l+1;
	int n2= r-m;
	int a1[n1], a2[n2];
	for (int i=0; i<n1; i++){
		a1[i] = arr[l+i];
	}
	for (int j=0; j<n2;j++)
		a2[j] = arr[m+1+j];

	int k=l;
	int i=0,j=0;
	while (i!=n1 && j!=n2){
		if (a1[i]<=a2[j])
			arr[k++]=a1[i++];
		else 
			arr[k++]=a2[j++];
	}
	while (i!=n1)
		arr[k++]=a1[i++];
	while (j!=n2)
		arr[k++]=a2[j++];
}

void mergesort(int a[], int l, int r){
	if (l<r){
		int m= (l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main(){

	int a[]={3,7,8,1,2,6,5};
	mergesort(a,0,6);
	for (int i=0; i<7; i++){
		cout<<a[i]<<' ';
	}
}