#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>


typedef struct _node {
	char data;
	struct _node* left;
	struct _node* right;
} node;


node* insert(node* root,char e){
	if (root==NULL) {
		node * x= (node*) malloc(sizeof(node)); 
		x->data=e;
		x->left=NULL;
		x->right=NULL;
		root = x;
		return root;
	}
	else if (e<root->data ){
		root->left=insert(root->left,e);
	}
	else root->right=insert(root->right,e);
	return root;
}

void inorder(node * root){
	if (root!=NULL){
		inorder(root->left);
		printf("%c ",root->data);
		inorder(root->right);
	}
}

void preorder(node * root){
	if (root!=NULL){
		printf("%c ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node * root){
	if (root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%c ",root->data);
	}
}

int main(){
	node * root=NULL;
	int n;
	printf("HOW MANY ELEMENTS? ",&n); scanf("%d",&n);
	printf("ENTER ELEMENTS: ");
	char s[100];
	scanf("%s",&s);
	for (int i=0;i<n;i++){
		if (i==0) root=insert(root,s[i]);
		else insert(root,s[i]);
	}
	printf("INORDER: ");
	inorder(root);
	printf("\nPREORDER: ");
	preorder(root);
	printf("\nPOSTORDER: ");
	postorder(root);
	
}


	

