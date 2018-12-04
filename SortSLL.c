#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *ptr;
struct node *head = NULL;

struct node *createNode(){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data:\t");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    return newNode;
}

void insert(){
    struct node *ptr;
    if(head == NULL){
        head = createNode();
    }
    else{
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = createNode();
    }
}

void sortlist(struct node *head){
    struct node *ptr1 = head;
    struct node *i;
    struct node *j;
    for(i = head;i->next != NULL;i= i->next){
        for(j = i->next;j != NULL;j = j->next){
            if(i->data > j->data){
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}
void display(struct node *head){
    struct node *ptr1;
    ptr1 = head;
    if(ptr1 == NULL){
        printf("\nLinked List is Empty!");
    }
    while(ptr1 != NULL){
        printf("%d  ",ptr1->data);
        ptr1 = ptr1->next;
    }
}
void main(){
    while(1){
        int ch;
    printf("\n1. Insert an element into the linked list");
    printf("\n2. Sort the Linked list");
    printf("\n3. Display the linked list");
    printf("\n4. EXIT!");

    printf("\nEnter your choice");
    scanf("%d",&ch);

    switch(ch){
        case 1: printf("Inserting...");
                insert();
                printf("Inserted Successfully");
                break;
        case 2:
                printf("Sorting the Linked List...");
                sortlist(head);
                printf("Sorted Successfully");
                break;
        case 3:
                printf("The sorted Linked List is: ");
                display(head);
                break;
        case 4:
                exit(0);
                break;
        default:
                printf("\nINVALID CHOICE!");
    }
}
}
