#include<stdio.h>
#include<ctype.h>
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
int isValidPostfix(char *postfix)
{
    //Checks for the validity of entered single digit postfix expression
    //Returns 1 if valid, 0 otherwise
    int noOfDigits = 0, noOfOperations = 0, isValidExpression = 1, i;

    if (isdigit(postfix[0]) && postfix[1] == '\0')
        return (isValidExpression);

    if (!(isdigit(postfix[0]) && isdigit(postfix[1])))
        return (--isValidExpression);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
            noOfDigits++;
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
            noOfOperations++;
        else
            return (--isValidExpression);
    }

    if (noOfDigits - noOfOperations != 1)
        return (--isValidExpression);

    return (isValidExpression);
}
void main(){

    char postfix[20];
    int result;
    while (1)
    {
        printf("Enter a valid postfix: ");
        scanf("%s", postfix);
        if (isValidPostfix(postfix))
            break;
        printf("Invalid expression\n");
    }

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
