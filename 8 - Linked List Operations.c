#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

#define size 10
int dq[size];
int front=-1;
int rear=-1;
int add_right(){
	if((front ==0 && rear==size-1)|| (front==rear+1)) {("\nOVERFLOW"); return 0;}
	if (front == -1){
		front=0; rear=0;}
	
	else{
		if (rear==size-1) rear=0;
		else rear=rear+1;}

		printf("\nEnter element: ");
		int e; scanf("%d",&e);
		 dq[rear]=e;
	}

int add_left(){
	if((front ==0 && rear==size-1)|| (front==rear+1)) {printf("\nOVERFLOW"); return 0;}
	if (front==-1){ front=0; rear=0;}
	else{
		if(front==0) front=size-1;
		else front--;}
		printf("\nEnter element: ");
		int e; scanf("%d",&e);
		 dq[front]=e;
	
	}


int delete_left(){
	if (front==-1){printf("\nUNDERFLOW"); return 0;}
	printf("\nDeleted element: %d",dq[front]);
	if(front ==rear) {front=-1;rear=-1;}
	else {
		if(front ==size-1) front =0;
		else front =front+1;
	}
}
int delete_right(){
	if (front==-1){printf("\nUNDERFLOW");return 0;}
	printf("\nDeleted element: %d",dq[rear]);
	if (front==rear) {front=rear=-1;}
	else{
		if (rear==0) rear=size-1;
		else rear--;
	}
}

int display(){
	int left=front;
	int right=rear;
	if(left==-1){ printf("\nEMPTY"); return 0;}
	printf("\nQUEUE CONTAINS: ");
	if (left<=right){
		while(left<=right) {printf("%d ",dq[left]); left++;}}
	else{
		while(left<=size-1){printf("%d ",dq[left]); left++;}
		left =0;
		while(front<=right) {printf("%d ",dq[left]); left++;}
	}
	}


int main(){
	
	int ch;
	printf("1. INPUT RESTRICTED\n2.OUTPUT RESTRICTED\n");
	scanf("%d",&ch);
	int op;
	if (ch==1){
		
		while (op!=5){
		printf("\n1. INSERT RIGHT\n2.DELETE LEFT\n3. DELETE RIGHT\n4. DISPLAY\n5. QUIT\n");
		 scanf("%d",&op);
		if (op==1) add_right();
		else if (op==2) delete_left();
		else if (op==3) delete_right();
		else if (op==4) display();}

	}
	else if (ch==2){
		while (op!=5){
		printf("\n1. INSERT RIGHT\n2. INSERT LEFT\n3. DELETE LEFT\n4. DISPLAY\n5. QUIT\n");
		scanf("%d",&op);
		if (op==1) add_right();
		else if (op==2) add_left();
		else if (op==3) delete_left();
		else if (op==4) display();}

	}



}



	

