#include<stdio.h>
#include<string.h>
#include<ctype.h>

bool isop(char x){
	char op[]="+-/*%^";
	for (int i=0;i<6;i++){
		if (x==op[i]) return 1;
	}
	return 0;
}

bool okpop(char x, char y){
	//y is incoming x already in stack
	//if incoming is lower precedence or same precedence
	if (x=='^') return 1;
	else if (y=='+' or y=='-') return 1;
	else if ((x=='*' or x=='/' or x=='%') and (y!='^')) return 1;
	else return 0;
}
char stack[100];
int top=-1;
void push(int e){
	top++;
	stack[top]=e;
}
void pop(){
	if (top!=0) top--;
}

int main(){
	char s[100];
	printf("INFIX EXPRESSION: ");
	scanf("%s",&s);
	char a[]="(";
	strcat(a,s);
	char b[]=")";
	strcat(a,b);
	int n=0;
	while (a[n]!='\0') n++;
	
	//int stack[100],j=-1;
	char exp[100];
	int k=-1;
	// a contains string
	for (int i=0;i<n;i++){
		if (a[i]=='(') {
			//j++;
			//stack[j]=a[i];
			push(a[i]);
			}
		else if (isalpha(a[i])){
			k++;
			exp[k]=a[i];
			
		}
		else if (a[i]==')'){
			while (stack[top]!='('){
				k++;
				exp[k]=stack[top];
				//j--;
				pop();
			}
			//j--;
			pop();
		}
		else if (isop(a[i])){
			while (stack[top]!='(' and okpop(stack[top],a[i])){
				k++;
				exp[k]=stack[top]; pop(); //j--;
			}
			push(a[i]);  //j++; stack[j]=a[i];
		} 
	}
	printf("POSTFIX EXPRESSION: ");
	for (int i=0;i<=k;i++){
		printf("%c",exp[i]);
	}
}