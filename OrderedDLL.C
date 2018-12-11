#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *newNode = NULL;
struct node *head = NULL;
struct node *tail = NULL;
struct node *ptr = NULL;
struct node *preptr = NULL;
createNode(int element){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = NULL;
}
void insert_data(int element){
    if(head == NULL){
        createNode(element);
        head = newNode;
        tail = newNode;
    }
    else if(head->data >= element){
        createNode(element);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if(tail->data <= element){
        createNode(element);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else{
        ptr = head;
        while(ptr->data < element){
            preptr = ptr;
            ptr = ptr->next;
        }
        createNode(element);
        newNode->prev = preptr;
        newNode->next = preptr->next;

        preptr->next->prev = newNode;
        preptr->next = newNode;
    }
}
void display(){
    ptr = head;
    printf("\nThe elements of the ordered linked list are:\t");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    while(1){
        printf("\n---------------");
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Exit!");
        printf("\n---------------");

        int ch,element;
        printf("\nEnter your choice:\t");
        scanf("%d",&ch);

    switch(ch){
        case 1:
                printf("\nEnter the data you wanna insert:\t");
                scanf("%d",&element);
                insert_data(element);
                printf("\nInserted Successfully!");
                break;
        case 2:
                display();
                break;
        case 3:
                exit(0);
                break;
        default:
                printf("\nInvalid choice");

        }
    }
}
