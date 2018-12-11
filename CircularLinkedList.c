#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *ptr = NULL;
struct node *searchPtr = NULL;
struct node *newNode = NULL;
struct node *head = NULL;

void createNode(){
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data:\t");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
}

void insert_begin(){

    createNode();
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }

    ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    newNode->next = head;
    head = newNode;
    ptr->next = head;

}

void insert_end(){
    if(head == NULL){
        insert_begin();
        return;
    }
    createNode();
    ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->next = head;
}
void insert_before(){
    if(searchPtr == head){
        insert_begin();
        return;
    }
    createNode();
    ptr = head;
    while(ptr->next != searchPtr){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = searchPtr;
}
void insert_after(){
    
    createNode();
    newNode->next = searchPtr->next;
    searchPtr->next = newNode;
}
void delete(){
    
    if(searchPtr == head){
        ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        head = head->next;
        ptr->next = head;
        return;
    }
    ptr = head;
    while(ptr->next != searchPtr){
        ptr = ptr->next;
    }
    ptr->next = searchPtr->next;

}
struct node* searchElement(int element){
    if(head == NULL){
        return NULL;
    }
    if(head->data == element){
        return head;
    }
    ptr = head->next;
    while(ptr != head){
        if(ptr->data == element){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;

}
void display(){
    if(head == NULL){
        printf("\nList is empty!");
        return;
    }
    printf("\nThe elements of the list are:\t");
    printf("%d",head->data);
    ptr = head->next;
    while(ptr != head){
        printf("%d",ptr->data);
        ptr = ptr->next;
    }
}
void main(){
    while(1){
        printf("\n---------------------------------------------------");
        printf("\n1. Insert an element in the beginning");
        printf("\n2. Insert an element at the end");
        printf("\n3. Insert an element before the given element");
        printf("\n4. Insert an element after the given element");
        printf("\n5. Delete the said element");
        printf("\n6. Display");
        printf("\n7. Exit!");
        printf("\n---------------------------------------------------");

        int ch;
        int element;
        printf("\nEnter your choice:\t");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                    insert_begin();
                    printf("\nInserted Successfully!");
                    break;
            case 2:
                    insert_end();
                    printf("\nInserted Successfully!");
                    break;
            case 3:
                    
                    printf("\nEnter the element you before which you wanna insert:\t");
                    scanf("%d",&element);
                    searchPtr = searchElement(element);

                    if(searchPtr == NULL){
                        printf("\nElement not found!");
                        break;
                    }
                    insert_before();
                    printf("\nInserted Successfully!");
                    break;
                
            case 4:
                    printf("\nEnter the element after which you wanna insert:\t");
                    scanf("%d",&element);
                    searchPtr = searchElement(element);

                    if(searchPtr == NULL){
                        printf("\nElement not found");
                        break;
                    }
                    insert_after();
                    printf("\nInserted Successfully!");
                    break;

            case 5:
                    printf("\nEnter the element you wanna delete:\t");
                    scanf("%d",&element);
                    searchPtr = searchElement(element);
                    if(searchPtr == NULL){
                        printf("\nElement not found");
                        break;
                    }
                    delete();
                    printf("\nDeleted Successfully!");
                    break;
            case 6:
                    display();
                    break;
            case 7:
                    exit(0);
                    break;
            default:
                    printf("\nINVALID CHOICE");
        }
    }
}
