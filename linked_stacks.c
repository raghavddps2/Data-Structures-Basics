#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
/* Can also use typedef here*/
struct stack{
    int data;
    struct stack *next;
};
/*Declaring the pointer with which we will keep track of the stack*/
struct stack *top = NULL;

/* Function to push an element into the stack*/
struct stack *push(struct stack *top,int val){
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;
    if(top == NULL){
        ptr->next = NULL;
        top = ptr;
    }
    else{
        ptr->next = top;
        top = ptr;
    }
    return top;
}

/*Function to pop an element from the stack*/
struct stack *pop(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if(top == NULL){
        printf("\nStack UNDERFLOW!");
    }
    else{
        top = top->next;
        printf("\nThe element deleted is: %d ",ptr->data);
        free(ptr);
    }
    return top;
}
/*Funtion to return tthe peak element in the stack!*/
int peak(struct stack *top){
    if(top == NULL){
        return -1;
    }
    else{
        return (top->data);
    }
}
/*Function to display elements of the stack*/
struct stack *display(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if(top == NULL){
        printf("\nStack is empty!");
    }
    else{
        printf("\nThe elements of the stack are:\t");
        while(ptr != NULL){
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}

/*The main function*/
void main(){
    int val,option;
    do{
        printf("\n**********Menu!**************");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.PEAK");
        printf("\n4.DISPLAY");
        printf("\n5.EXIT");

        printf("\nEnter your choice:\t");
        scanf("%d",&option);

        switch(option){
            case 1:
                    printf("\nEnter the Element");
                    scanf("%d",&val);
                    top = push(top,val);
                    break;
            case 2:
                    top = pop(top);
                    break;
            case 3:
                    val = peak(top);
                    if(val != -1){
                        printf("T\nhe value at the top of the stack is %d",val);
                    }
                    else{
                        printf("\nStack is empty!");
                    }
                    break;
            case 4:
                    top = display(top);
                    break;
            case 5:
                    break;
            default:
                    printf("\nINVALID CHOICE");
        }
    }while(option != 5);
}
