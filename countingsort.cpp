#include<bits/stdc++.h>
using namespace std;

void csort(int arr[], int n, int  k){

	int count[k]={0};

	for (int i=0; i<n;i++){      //counting and storing frequency of all elements
		count[arr[i]]++;
	}

	for (int i=1;i<k;i++){			//cummulative sum
		count[i]+=count[i-1];
	}

	int temp[n];
	for (int i=0;i<n;i++){			//temporary copy of original array 
		temp[i]=arr[i];
	}

	for (int i=0;i<n;i++){						//placement at proper index
		arr[count[temp[i]]-1]=temp[i];
		count[temp[i]]--;
	}
}

int main(){

	int arr[]={1,5,3,7,8,9,2,4};
	csort(arr,8,10);
	for (int i=0;i<8;i++){
		cout<<arr[i]<<' ';
	}

}