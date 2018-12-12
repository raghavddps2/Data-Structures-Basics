#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

struct tree{
    char data;
    struct tree *left, *right;
};
struct tree *node = NULL;
int top = -1;
struct tree *stack[20];

void push(struct tree *node){
    stack[++top] = node;
}
struct tree* pop(){
    return stack[top--];
}
void operand(char a){
    node = (struct tree*)malloc(sizeof(struct tree));
    node->data = a;
    node->right = NULL;
    node->left = NULL;
    push(node);
}
void operator(char b){
    node = (struct tree*)malloc(sizeof(struct tree));
    node->data = b;
    node->right = pop();
    node->left = pop();
    push(node);
}
int check(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/'){
        return 2;
    }
    else{
        return 1;
    }
}
int calculate(struct tree* node){
    char s = node->data;
    int ch = check(s);
    if(ch == 1){
        return node->data-48;
    }
    else if(ch == 2){
        if(s == '+'){
            return (calculate(node->left) + calculate(node->right));
        }
        else if(s == '-'){
            return (calculate(node->left) - calculate(node->right));
        }
        else if(s == '*'){
            return (calculate(node->left) * calculate(node->right));
        }
        else if(s == '/'){
            return (calculate(node->left) / calculate(node->right));
        }
    }
    else{
        printf("\nSome error occured!");
        return 0;
    }
}
void inOrderTraversal(struct tree* node){
    if(node != NULL){
        inOrderTraversal(node->left);
        printf("%c",node->data);
        inOrderTraversal(node->right);
    }
}
void main(){

    char postfix[20];
    int result;
    printf("\nEnter the postfix expression:\t");
    scanf("%s",postfix);

    for(int i=0;postfix[i] != '\0';i++){
        int ch = check(postfix[i]);
        if(ch == 1){
            operand(postfix[i]);
        }
        else{
            operator(postfix[i]);
        }
    }
    result = calculate(stack[top]);
    printf("\nThe value of thebexpression is: %d",result);

    printf("\nThe Infix expression is :\t");
    inOrderTraversal(stack[top]);
}
