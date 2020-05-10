#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	int v;
	_node* N;
} node;
node* root = NULL;

void add(int x){
	node* ne = (node*) malloc(sizeof(node));
	ne->v =x;
	ne->N = NULL;
	node* temp = root;
	while (temp->N) temp = temp->N;
	temp->N = ne;
}
node* rev(node* p){
	if (!p) return 0;
	if (p->N){
		node* q = rev(p->N);
		p->N->N = p;
		p->N = NULL;
		return q;
	}
	return p;
}
void print(){
	node* temp = root;
	while (temp){
		printf("%d->", temp->v);
		temp= temp->N;
	}
}
int main(){
	root = (node*) malloc(sizeof(node));
	root->v =0;
	root->N =NULL;
	add(1),
	add(2),	
	add(3),	
	add(4),	
	add(5),	
	add(6);
	root=rev(root);	
	print();

}