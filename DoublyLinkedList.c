#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node* next;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node *ptr = NULL;
struct node *searchPtr = NULL;
struct node *newNode = NULL;
void createNode(){
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:\t");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
}
void insert_begin(){
    createNode();
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insert_end(){
    if(head == NULL){
        insert_begin();
        return;
    }
    createNode();
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void insert_before(){
    if(searchPtr == head){
        insert_begin();
        return;
    }
    createNode();
    newNode->prev = searchPtr->prev;
    newNode->next = searchPtr;

    searchPtr->prev->next = newNode;
    searchPtr->prev = newNode;

}

void insert_after(){

    if(searchPtr == tail){
        insert_end();
        return;
    }
    
    createNode();
    newNode->prev = searchPtr;
    newNode->next = searchPtr->next;

    searchPtr->next->prev = newNode;
    searchPtr->next = newNode;
}
void delete(){
    if(searchPtr == head){
        head = head->next;
        head->prev = NULL;
        return;
    }
    if(searchPtr == tail){
        tail = tail->prev;
        tail->next = NULL;
        return;
    }
    searchPtr->next->prev = searchPtr->prev;
    searchPtr->prev->next = searchPtr->next;
}
struct node* searchElement(int element){

    ptr = head;
    while(ptr != NULL){
        if(ptr->data == element){
            printf("hi!");
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}
void display(){
    if(head == NULL){
        printf("\nThe Linked List is empty");
        return;
    }
    printf("\nThe elements of the linked list are:\t");
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}


void main(){
    while(1){
        printf("\n-----------------------------------------------");
        printf("\n1. Insert an element in the beginning");
        printf("\n2. Insert an element in the end");
        printf("\n3. Insert an element before a given element");
        printf("\n4. Insert an element after a given element");
        printf("\n5. Delete the said element");
        printf("\n6. Dislay");
        printf("\n7. Exit!");
        printf("\n-----------------------------------------------");

        int ch,element;
        printf("\nEnter your choice:\t");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                    insert_begin();
                    printf("\nInserted Successfully");
                    break;
            case 2:
                    insert_end();
                    printf("\nInserted Successfully");
                    break;
            case 3:
                    printf("\nEnter the eleemnt before which you wanna insert:\t");
                    scanf("%d",&element);

                    searchPtr = searchElement(element);
                    if(searchPtr == NULL){
                        printf("\nElement not found!");
                        break;
                    }
                    insert_before();
                    printf("\nInserted Successfully");
                    break;
            case 4:
                    printf("\nEnter the eleemnt after which you wanna insert:\t");
                    scanf("%d",&element);

                    searchPtr = searchElement(element);
                    if(searchPtr == NULL){
                        printf("\nElement not found!");
                        break;
                    }
                    insert_after();
                    printf("\nInserted Successfully");
                    break;
            case 5:
                    printf("\nEnter the eleemnt you wanna delete:\t");
                    scanf("%d",&element);

                    searchPtr = searchElement(element);
                    if(searchPtr == NULL){
                        printf("\nElement not found!");
                        break;
                    }
                    delete();
                    printf("\nDeleted Successfully");
                    break;
                    
            case 6:
                    display();
                    break;
            case 7:
                    exit(0);
                    break;
            default:
                    printf("\nInvalid choice!");
        }
    }
}
