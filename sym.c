#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

typedef struct _node
{
	int data;
	struct _node* left;
	struct _node* right;
} node;

node* root1=NULL;
node* root2=NULL;

bool isBST(node* root){
	if (root!=NULL){
		static node *prev=NULL;
		if (!isBST(root->left)) return 0;
		if (prev && prev->data>root->data) return 0;
		prev =root;
		return isBST(root->right);
	}
	return 1;
}

bool isSYM(node* root1, node * root2){
	if (root1==NULL && root2==NULL) return 1;

	else if (root1!=NULL && root2!=NULL && root1->data == root2->data) 
		return (isSYM(root1->left, root2->right) && isSYM(root1->right,root2->left));

	return 0;
}

node* create(int e){
	node* temp=(node*) malloc(sizeof(node));
	temp->data=e;
	temp->left=temp->right=NULL;
	return temp;
}
int main(){

	root1=create(8);
	root1->left=create(6);
	root1->right=create(9);
	root1->left->left=create(2);
	root1->left->right=create(7);
	root1->left->left->right=create(9);
	


	if (isBST(root1))
		 printf("1 IS A BINARY SEARCH TREE\n");
	else printf("1 IS NOT A BINARY SEARCH TREE\n");
	
	printf("\n\n");
}







