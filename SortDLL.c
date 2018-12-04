#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *createNode(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:\t");
    scanf("%d",&newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
}
void insert(){
    struct node *ptr;
    if(head == NULL){
        ptr = createNode();
        head = ptr;
        tail = ptr;
    }
    else{
        ptr = createNode();
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
}
void sort(){
    struct node *i;
    struct node *j;

    for(i = head;i->next != NULL;i = i->next){
        for(j = i->next;j != NULL;j = j->next){
            if(i->data > j->data){
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}
void display(){
    struct node *ptr = head;
    if(head == NULL){
        printf("\nLinked list is empty");
    }
    else{
        ptr = head;
        while(ptr != NULL){
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
    }
}
void main(){

    while(1){
        int ch;
        printf("\n1. Insert the data in the linked list");
        printf("\n2. Sort the linked list");
        printf("\n3. Display the linked list");
        printf("\n4. Exit!");

        printf("\nEnter your choice:\t");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                    printf("Inserting...");
                    insert();
                    printf("Inserted Successfully");
                    break;
            case 2:
                    printf("Sorting...");
                    sort();
                    printf("Sorted Successfully");
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                    printf("\nInvalid choice!");
                    break;
        }
    }
}
