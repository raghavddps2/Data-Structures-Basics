#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
// This part of the code declares the structure for the linked list.(Doubly linked list, so two pointers)
struct node{
    struct node *prev;
    char s;
    struct node *next;
};
struct node *head = NULL; //This declares the head pointer
struct node *tail = NULL; //This declares the tail pointer

//This function creates a node for the linked list, and return sthe pointer of thet created node.
struct node *createNode(char s){
    struct node *ptr2;
    ptr2 = (struct node*)(malloc(sizeof(struct node)));
    ptr2->s = s;
    ptr2->prev = NULL;
    ptr2->next = NULL;
    return ptr2;
}
//This is the function that basically creates the linked list.
void addNode(char s){
    struct node *ptr1;
    ptr1 = createNode(s);
    if(head == NULL){
        head = ptr1;
        tail = ptr1;
        return;
    }

    tail->next = ptr1;
    ptr1->prev = tail;
    tail = ptr1;
}
//This function checks whether the list is a pallindrome or not.
int pallindrome(){

    struct node *ptra;
    struct node *ptrb;
    ptra = head;
    ptrb = tail;

    while(ptra != ptrb){

        if(ptra->s != ptrb->s){
            return 0;
            
        }
        ptra = ptra->next;
        ptrb = ptrb->prev;
    }
    return 1;
}
void main(){
    char s[20];
    printf("Enter the String:\t");
    scanf("%s",s);

    for(int i=0; s[i] != '\0';i++){
        addNode(s[i]);
    }

    if(pallindrome()){
        printf("\nThe entered string is a pallindrome.");
    }
    else{
        printf("\nThe entered string is not a pallindrome.");
    }
}
