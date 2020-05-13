#include<stdio.h>
#include<stdlib.h>

//STRUCTURE DECLARATION
struct twostacks{
	int n,top1,top2, *arr;} ;

//FUNCTION TO CREATE STACK
struct twostacks* create_stack(int len){
	struct twostacks* tmp= (struct twostacks*) malloc(sizeof(struct twostacks));
	tmp->top1=-1;
	tmp->top2=len; tmp->n=len;
	tmp->arr =(int*) malloc(sizeof(int)*len);
	return tmp;
}


//STACK 1 OPERATIONS
void push1(struct twostacks* s){
	if (s->top1 < s->top2-1){
		printf("\nEnter element: ");
		int e;
		scanf("%d",&e);
		s->top1++;
		s->arr[s->top1]=e;
		printf("\n%d Pushed to Stack 1",e);
	}
	else printf("\nStack Overflow!!");
}

void pop1(struct twostacks*s){
	if (s->top1<0) printf("\nStack 1 Underflow");
	else{
		printf("\nElement Popped From Stack 1: %d",s->arr[s->top1]);
		s->top1--;
	}
}

void peek1(struct twostacks*s){
	if (s->top1<0) printf("\nStack 1 empty");
	else
	printf("\nTopmost element of Stack 1: %d", s->arr[s->top1]);
}
void display1(struct twostacks*s){
	if (s->top1<0) printf("\nStack 1 empty");
	else{
		printf("\nStack 1 consists: ");
		for (int i=0;i<=s->top1;i++){
			printf("%d ",s->arr[i]);
		}
	}
}
//STACK 2 OPERATIONS
void push2(struct twostacks*s){
	if (s->top1 < s->top2-1){
		printf("\nEnter element: ");
		int e;
		scanf("%d",&e);
		s->top2--;
		s->arr[s->top2]=e;
		printf("\n%d Pushed to Stack 2",e);
	}
	else printf("\nStack Overflow!!");
}

void pop2(struct twostacks*s){
	if (s->top2==s->n) printf("\nStack 2 Underflow");
	else{
		printf("\nElement Popped From Stack 2: %d",s->arr[s->top2]);
		s->top2++;
	}
}

void peek2(struct twostacks*s){
	if (s->top2==s->n) printf("\nStack 2 empty");
	else
	printf("\nTopmost element of Stack 2: %d", s->arr[s->top2]);
}
void display2(struct twostacks*s){
	if (s->top2==s->n) printf("\nStack 2 empty");
	else{
		printf("\nStack 2 consists: ");
		for (int i=s->n-1;i>=s->top2;i--){
			printf("%d ",s->arr[i]);
		}
	}
}
int main(){
	printf("Enter total size: ");
	int n;
	scanf("%d",&n);
	struct twostacks* stk= create_stack(n);
	int c=1;

	while(c){
		printf("\n\nENTER STACK NO (1/2): ");
		int ch; scanf("%d",&ch);
		printf("\n\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. QUIT\n\nENTER UR CHOICE: ");
		scanf("%d",&c);
		system("cls");
		if (c==5) break;
		if (ch==1){
			if (c==1) push1(stk);
			else if (c==2) pop1(stk);
			else if (c==3) peek1(stk);
			else if (c==4) display1(stk);
		}
		else if (ch==2){
			if (c==1) push2(stk);
			else if (c==2) pop2(stk);
			else if (c==3) peek2(stk);
			else if (c==4) display2(stk);
		}
		}


}
