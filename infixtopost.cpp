#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(int value){
	if (top==MAX-1){
		printf("Stack overflow\n");
	}else{
		stack[++top]=value;
	}
}
char pop(){
	if(top ==-1){
		printf("Stack is empty\n");
	}else{
		return stack[top--];
	}
}
int pre(char op){
	switch(op){
		case('^'):
			return 3;
		case('/'):
		case('*'):
			return 2;
		case('+'):
		case('-'):
			return 1;
		default:
			return 0;
	}
}
void intopostfix( char infix[], char postfix[]){
	int i,j=0;
	char ch;
	strcat(infix, ")");
    push('(');
	for(i=0;infix[i]!='\0';i++){
		ch=infix[i];
		if(isalnum(ch)){
		postfix[j++]=ch;
	}else if(ch=='('){
		push(ch);
	}else if(ch==')'){
		while(stack[top]!='('){
			postfix[j++]=pop();
		}
		pop();
	}else{
		while(pre(stack[top])>=pre(ch)){
			postfix[j++]=pop();
	}
		push(ch);
	}
}
	postfix[j] = '\0';
}
int main(){
	char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);   
    
    intopostfix(infix, postfix);
    
    printf("Postfix: %s\n", postfix);
    return 0;
}


