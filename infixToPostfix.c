#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 40

char stack[SIZE];
int top = -1;

int isValidInfix(char infix[]){

    int noOfOpeningBrackets=0;
    int noOfClosingBrackets=0;
    int noOfOperations=0;
    int noOfDigits=0;
    int isValidInfix = 1;

    for(int i=0;infix[i]!='\0';i++){
        if(infix[i] == '('){
            noOfOpeningBrackets++;
        }
        else if(infix[i] == ')'){
            noOfClosingBrackets++;
        }
        else if(isalnum(infix[i])){
            noOfDigits++;
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*'|| infix[i] == '/' || infix[i] == '^' || infix[i] == '%' || infix[i] == '$'){
            noOfOperations++;
        }
        else{
            printf("\nThis is not a valid Infix expression or it contains any other operator other tha *,+,-,/ and a diiferent barckets than ()");
            return (--isValidInfix);
        }
    }
    if((noOfDigits-noOfOperations != 1) || (noOfOpeningBrackets != noOfClosingBrackets)){
        return (--isValidInfix);
    }
    return isValidInfix;
}
void push(char element){
    if(top == SIZE-1){
        printf("Stack Overflow");
    }
    else{
        stack[++top] = element;
    }
}
char peak(){
    if(top == -1){
        return '0';
    }
    else{
        return stack[top];
    }
}

int priority(char ch){
    
    switch(ch){
        case '(':
            return 1;
        case '+':
            return 2;
        case '-':
            return 2;
        case '*':
        case '%':
            return 3;
        case '/':
            return 3;
		case '^':
        case '$':
			return 4;
        default:
            return -1;
    }
}
char pop(){
    if(top == -1){
        return '0';
    }
    else{
        return (stack[top--]);
    }
}
char* infixToPostfix(char infix[],char postfix[]){
    int j=-1;
    for(int i=0;infix[i]!='\0';i++){
        if(infix[i] == '('){
            push(infix[i]);
        }
        else if(isalnum(infix[i])){
            postfix[++j] = infix[i];
        }
        else if(infix[i] == ')'){
            while(peak() != '('){
                postfix[++j] = pop();
            }
            pop();
        }
        else{
            while(priority(peak())>=priority(infix[i])){
                postfix[++j] = pop();
            }
            push(infix[i]);
        }
    }
    while(peak() != '0'){
        postfix[++j] = pop();
    }
    return postfix;
}

void main(){
    char infix[SIZE];
    char postfix[SIZE];
        printf("\n*********************************************");
        printf("\nProgram to convert infix to postfix");
    while(1){
        printf("\nEnter the infix expression:\t");
        gets(infix);
        if(isValidInfix(infix)){
            break;
        }
        else{
            printf("\nInvalid Expression.");
        }
    }

  
    printf("\nThe postfix expression is:\t %s",infixToPostfix(infix,postfix));
}
