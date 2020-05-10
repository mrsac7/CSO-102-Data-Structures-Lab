#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
  
 
struct polishstack 
{ 
    int top; 
    int capacity; 
    int* arr; 
}; 
  
struct polishstack* createStack( int cap ) 
{ 
    struct polishstack* stack;
	stack = (struct polishstack*) malloc(sizeof(struct polishstack)); 
    stack->top = -1; 
    stack->capacity = cap; 
    stack->arr = (int*) malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

char pop(struct polishstack* stack) 
{    int k=stack->arr[stack->top];
      stack->top-- ;
	  return(k); 
} 
void push(struct polishstack* stack, char p) 
{   
      stack-> top++;
    stack->arr[stack->top] = p; 
} 

int prec(char ch)
{
    if(ch=='+'|| ch=='-') 
        return 1; 
   
    else if(ch=='%'||ch=='*'||ch=='/')
        return 2; 
    
	else if(ch=='^')
        return 3; 
    
    else
    return -1; 
}

   
int main() 
{ 
    char infix[100],postfix[100];
    scanf("%s",infix);
    int i,k=-1; 
     struct polishstack* stack = createStack(strlen(infix));  
  
    for (i = 0; infix[i]; ++i) 
    { 
         
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) 
            postfix[++k] = infix[i]; 
           
        else if (infix[i] == '(') 
            push(stack, infix[i]);
            
        else if (infix[i] == ')') 
        { 
            while (stack->arr[stack->top]!= '(') 
                postfix[++k] = pop(stack);
                
             pop(stack);
        } 
        else 
        { 
            while (prec(infix[i]) <= prec(stack->arr[stack->top])) 
                postfix[++k] = pop(stack); 
            push(stack, infix[i]); 
        } 
       
    } 
    
    while (stack->top!=-1)
        postfix[++k] = pop(stack ); 
  
    postfix[++k] = '\0'; 
    printf("%s",postfix); 
 
    return 0; 
}