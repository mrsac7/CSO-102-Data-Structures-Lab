#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>


#define MAX 100

int heap[MAX];
int n=0;

void enqueue(){
	printf("\nEnter element: ");
	int e; scanf("%d",&e);
	int pos=n; n++;
	heap[pos] = e;
	while (pos>0){
		int par= (pos+1)/2-1;
		if (heap[pos]<=heap[par]){
			return;
		}
		else{
			int temp=heap[pos];
			heap[pos]=heap[par]; heap[par]=temp;
			pos=par;
		}
	}
}

void dequeue(){
	int last=heap[n-1];
	n--;
	int ptr=0, left=1, right=2;
	heap[ptr] = last;

	while (left<n){
		if (heap[ptr]>= heap[left] && heap[ptr]>=heap[right]) return;
		if (heap[ptr]<heap[left]){
			int temp=heap[ptr];
			heap[ptr]=heap[left];heap[left]=temp;
			ptr=left;
		}
		else{
			int temp=heap[ptr];
			heap[ptr]=heap[left];heap[left]=temp;
			ptr=right;
		}
		left=2*(ptr+1) -1;
		right=left+1;

	}
}

void display(){
	int t=n;
	int arr[t];
	for (int i=0;i<t;i++){
		arr[i]=heap[i];
	}
	printf("\nQueue Contains: ");
	for (int i=0;i<t;i++){
		printf("%d ",heap[0]);
		dequeue();
	}
	for (int i=0;i<t;i++){
		heap[i]=arr[i];
	}
	n=t;
}

int main(){
	for(;;){
		printf("\n1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE: ");
		int ch; scanf("%d",&ch);
		if (ch==4) break;
		else if(ch==1) enqueue();
		else if (ch==2) dequeue();
		else if (ch==3) display();
	}
}