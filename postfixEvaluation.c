#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 50

int stack[SIZE];
int top =-1;

int isEmpty(){
    return (top == -1);
}

int isFull(){
    return (top == SIZE-1);
}
void push(int element){
    if(isFull()){
        printf("Stack Overflow");
    }
    else{
        stack[++top] = element;
    }
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow");
        return -1;
    }
    else{
        return stack[top--];
    }
}

int isValidPostfix(char postfix[]){
    int isValidpostfix=1;
    int noOfOperators=0;
    int noOfDigits=0;
    if((isdigit(postfix[0])) && (postfix[1]=='\0')){
        return (--isValidpostfix);
    }
    else if(!isdigit(postfix[0]) && (isdigit(postfix[1]))){
        return (--isValidpostfix);
    }
    else {
        for(int i=0;postfix[i]!='\0';i++){

            if(isdigit(postfix[i])){
                noOfDigits++;
            }
            else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'){
                noOfOperators++;
            }
            else{
                return (--isValidpostfix);
            }
        }
        if((noOfDigits - noOfOperators != 1)){
                return (--isValidpostfix);
        }
        return (isValidpostfix);
    }
}
/*This is valid only for single-digit postfix expression, like no multiple digits in the same no are allowed. Like it cannot
    evaluate 54+32, rather can evaluate 5+4 and single digit like that.
*/ 
void postfixEvaluation(char postfix[]){
    int isDivideZero;
    for(int i=0;postfix[i]!='\0';i++){
        if(isdigit(postfix[i])){
            push(postfix[i]-'0');
        }
        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'){
            int op1 = pop();
            int op2 = pop();

            if(postfix[i] == '+'){
                push(op2 + op1);
            }
            else if(postfix[i] == '-'){
                push(op2 - op1);
            }
            else if(postfix[i] == '*'){
                push(op2 * op1);
            }
			else if(postfix[i] == '^'){
				push(op2^op1);
			}
            else{
                if(op2 == 0 && op1 == 0){
                    isDivideZero = 1;
                    break;
                }
                else if(op2 == 0){
                    isDivideZero = 2;
                    break; 
                }
                else{
                    push(op2/op1);
                }
            }
        }
    }
    if(isDivideZero == 1){
        printf("\nThe result is:\t NaN");
    }
    else if(isDivideZero == 2){
        printf("\nThe result is:\t%c",236); //236 is the Ascii code for Infinity
    }
    else{
        printf("\nThe result is: %d\t",pop());
    }
}
void main(){
    char postfix[SIZE];
    while(1){
        printf("\n****************************************");
        printf("\nEnter the postfix Expression:\t");
        scanf("%s",postfix);
        if(isValidPostfix(postfix)){
            break;
        }
        else{
            printf("\nInvalid Expression");
        }
        
    }
    postfixEvaluation(postfix);
}
