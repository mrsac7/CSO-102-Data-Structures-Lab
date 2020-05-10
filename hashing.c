#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 500

typedef struct _node{
	char val[1000];
	char str[1000];
	struct _node * next;
} node;

node *arr[max]={NULL};

bool comp(char a[],char b[]){
	int c=0;
	while (a[c]==b[c]){
		if (a[c]=='\0'|| b[c]=='\0') break;
		c++;
	}
	if (a[c]=='\0' && b[c]=='\0') return 1;
	else return 0;
}


void insert(){
	char s[1000];
	printf("\nEnter key: ");
	scanf("%s",s);
	char s2[1000];
	printf("\nEnter value: ");
	scanf("%s",s2);

	int i=0;
	int p=1;
	int key=0;
	while (s[i]!='\0'){
		if (p>12167) p=1;
		key=key +int(s[i])*(p);
		p*=23;
		i++;

	}
	key=key%500;
	node *ptr= (node*) malloc(sizeof(node));
	strcpy(ptr->str,s);
	strcpy(ptr->val,s2);
	ptr->next  =NULL;
	if (!arr[key]) arr[key]=ptr;
	else if (comp(arr[key]->str,ptr->str)){ printf("Key already exists!"); return;}
	else{
		node *temp=arr[key];
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=ptr;
	}
}


void search(){
	char s[1000];
	printf("\nEnter key: ");
	scanf("%s",s);
	int i=0;
	int p=1;
	int key=0;
	while (s[i]!='\0'){
		if (p>12167) p=1;
		key=key +int(s[i])*(p);
		p*=23;
		i++;

	}
	key=key%500;
	if (arr[key]==NULL) printf("String is not present");
	else if (comp(arr[key]->str,s)) printf("\nValue: %s",arr[key]->val);
	else{
		node* temp=arr[key]->next;
		while(temp){
			if (comp(temp->str,s)) {printf("\nValue: %d",temp->val); return;}
			temp=temp->next;
		}
		printf("\nString is not present");
	}
}

void del(){
	char s[1000];
	printf("\nEnter key: ");
	scanf("%s",s);
	int i=0;
	int p=1;
	int key=0;
	while (s[i]!='\0'){
		if (p>12167) p=1;
		key=key +int(s[i])*(p);
		p*=23;
		i++;

	}
	key=key%500;
	if (arr[key]==NULL) printf("String is not present");
	
	
	else if (comp(arr[key]->str,s)){
		node *temp=arr[key];
		arr[key]=arr[key]->next;
		free(temp);
		printf("\nString found and deleted");

	}
	else{
		node* temp=arr[key]->next;
		while(temp!=NULL){
			if (comp(temp->str,s)) {
				node* t=temp;
				temp=temp->next;
				free(t); printf("\nString found and deleted"); return;
			}
		}
		printf("\nString is not present");
	}
}

int main(){
	printf("1.INSERT\n2.SEARCH\n3.DELETE\n4.EXIT\n");
	int ch;
	while (ch!=4){
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		if (ch==1) insert();
		else if (ch==2) search();
		else if (ch==3) del();

	}

}