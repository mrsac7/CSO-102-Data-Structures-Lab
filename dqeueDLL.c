#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

#define size 10



typedef struct _node{
	int data;
	struct _node* left, *right;
} node;


node*front=NULL;
node* rear=NULL;
int num=0;

int add_left(){
	if (num==size) printf("\nOVERFLOW");
	else{
		node* temp= (node*) malloc (sizeof(node));
		printf("\nEnter element: ");
		int e; scanf("%d",&e);
		temp->data=e;
		temp->left=NULL;
		temp->right=NULL;
		if (front==NULL) {front =temp; rear=temp;}
		else {
			node * ptr= front;
			front=temp;
			front->right=ptr;
			ptr->left=front;
			}
		num++;
	}

}
int add_right(){
	if (num==size) printf("\nOVERFLOW");
	else{
		node * temp= (node*) malloc(sizeof(node));
		printf("\nEnter element: ");
		int e; scanf("%d",&e);
		temp->data=e;
		temp->left=NULL;
		temp->right=NULL;
		if (front==NULL){front =temp;rear=temp;}
		else{
			node* ptr= rear;
			rear=temp;
			ptr->right=rear;
			rear->left=ptr;
		}
		num++;
	}
}

int delete_left(){
	if (front==NULL){printf("\nUNDERFLOW"); return 0;}
	printf("\nDeleted Element: %d",front->data);
	num--;
	if (front==rear) {front=NULL;rear=NULL;}
	else{
		node * temp=front;
		front=front->right;
		front->left=NULL;
		free(temp);
	}

}

int delete_right(){
	if (front==NULL){printf("\nUNDERFLOW"); return 0;}
	printf("\nDeleted Element: %d",rear->data);
	num--;
	if (front==rear) {front =NULL; rear=NULL;}
	else{
		node * temp= rear;
		rear=rear->left;
		rear->right=NULL;
		free(temp);
	}
}

int display(){
	node * temp= front;
	printf("\nQUEUE CONTAINS: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->right;}
}

int main(){
	
	int ch;
	printf("1. INPUT RESTRICTED\n2. OUTPUT RESTRICTED\n");
	scanf("%d",&ch);
	int op;
	if (ch==1){
		
		while (op!=5){
		printf("\n1. INSERT RIGHT\n2. DELETE LEFT\n3. DELETE RIGHT\n4. DISPLAY\n5. QUIT\n");
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


