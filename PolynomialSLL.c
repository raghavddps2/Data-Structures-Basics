#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int a,b,c;
    struct node *next;
};
struct node *head;
struct node *ptr;

/*
    This function creates the linked list and stores the value of the expression in the list.
*/
void insert(){
    struct node *ptr1;
    ptr1 = (struct node *)malloc(sizeof(struct node));
    ptr1->next = NULL;
    printf("\nEnter the coefficient of a:\t");
    scanf("%d",&ptr1->a);
    printf("\nEnter the coefficient of b:\t");
    scanf("%d",&ptr1->b);
    printf("\nEnter the coefficient of c:\t");
    scanf("%d",&ptr1->c);

    if(head == NULL){
        head = ptr1;
        return;
    }
    else{
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = ptr1;
    }
}
/*
    This function sums all the values present in the linked list and gives the sum of the polynomial.
*/
void sum(){
    int a=0;
    int b=0;
    int c=0;

    if(head == NULL){
        printf("\nNo Expression Added!");
    }
    else{
        ptr = head;
        while(ptr != NULL){
            a += ptr->a;
            b += ptr->b;
            c += ptr->c;
            ptr = ptr->next;
        }
        printf("\nThe sum of the expressions entered is: %dx^2 + %dx + %d ",a,b,c);
    }
}
void main(){

    while(1){
        printf("\n1. Enter the expression");
        printf("\n2. Display the sum of the expressions");
        printf("\n3. Exit!");
        int ch;
        printf("\nEnter your choice:\t");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                    insert();
                    break;

            case 2:
                    sum();
                    break;
            
            case 3:
                    exit(0);

            default:
                    printf("\nINVALID CHOICE!");
        }
    }
}
