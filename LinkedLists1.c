#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};
struct node *start;
/* Function to create a linked list!!*/
struct node *create_ll(struct node *start){

    struct node *ptr,*new_node;
    int num;
    printf("\nEnter the value you wwanna insert and enter -1 to exit\t");
    scanf("%d",&num);
    
    while(num != -1){
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
            if(start == NULL){
                start = new_node;
                new_node->next = NULL;
            }
            else{
                ptr = start;
                while(ptr->next !=NULL){
                        ptr = ptr->next;
                }
                ptr->next = new_node;
                new_node->next = NULL;
            }
            printf("\nEnter the number you wanna insert in the linked list\t");
            scanf("%d",&num);
    }
    return start;
} 
struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    printf("\nThe elements of the linked list are:\t");
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    return start;
}
/* Function to insert a node at the begnning*/
struct node *insert_begin(struct node *start){
    struct node *ptr,*new_node;
    int num;
    printf("\nEnter the number you wanna insert in the beginning of the list\t");
    scanf("%d",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}
/*Function to insert a node at the nd*/
struct node *insert_end(struct node *start){
    struct node *ptr,*new_node;
    int num;
    printf("\nEnter the number you wanna insert in the end of the list\t");
    scanf("%d",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;  
    ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    
    ptr->next =new_node;
    /*
        Here it is done as ptr->next = new_node, because we are changimg the pointing location(next) of the ptr node;
    */

    return start;
}
struct node *insert_before(struct node *start){
    struct node *ptr,*new_node,*preptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    int val;
    int num;
    printf("Enter the value of the element before which you wanna add the new element");
    scanf("%d",&val);
    printf("Enter the value of the new element to be enetered");
    scanf("%d",&num);
    ptr = start;
    new_node->data = num;
    while(ptr->data != val){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;

    return start;
}
struct node *insert_after(struct node *start){
    struct node *ptr,*new_node,*postptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    int val;
    int num;
    printf("Enter the value of the element after which you wanna add the new element");
    scanf("%d",&val);
    printf("Enter the value of the new element to be enetered");
    scanf("%d",&num);
    ptr = start;
    new_node->data = num;
    while(ptr->data != val){
        ptr = ptr->next;
        postptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = postptr;

        return start;
}
struct node *delete_begin(struct node *start){
    struct node *ptr;
    ptr  = start;
    start = ptr->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start){
    struct node *ptr,*preptr;
    ptr = start;
    while(ptr->next != NULL){
            preptr = ptr;
            ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}
struct node *delete(struct node *start){
    struct node *ptr,*preptr,*postptr;
    ptr = start;
    int num;
    printf("Enter the element you wanna delete");
    scanf("%d",&num);
    //Added this statement after getting stuck in the lab test, doesn't worked initially if there are only two statements as the first onw will have no initial pointer.
    if(ptr->data == num){
        start = delete_begin(start);
        return start;
    }
    else{
        while(ptr->data != num){
            preptr = ptr;
            ptr = ptr->next;
            postptr = ptr->next;
        }
    } 
    preptr->next = postptr; //Learn as to why i wrote like that. This is because, we are like from postptr to preptr, consider it like an arrow.
    free(ptr);

    return start;
}

void main(){
    
    int option;

    do{ 
        printf("\n-------------------------------------------------------------------------------------------");
        printf("\n***************Menu*****************");
        printf("\n1.Create a linked list");
        printf("\n2.Display the linked list");
        printf("\n3.Insert a number in the beginning");
        printf("\n4.Insert a number in the end");
        printf("\n5.Insert an elemnet before a given element");
        printf("\n6.Insert an element afer a given element");
        printf("\n7.Delete an element from the beginning");
        printf("\n8.Delete an element from the end");
        printf("\n9.Delete the entered element");
        printf("\n10. Press 12 to exit");
        
        printf("\nEnter your choice\t");
        scanf("%d",&option);

        switch(option){
            case 1: start = create_ll(start);
                    break;
            case 2: start = display(start);
                    break;
            case 3: start = insert_begin(start);
                    break;
            case 4: start = insert_end(start);
                    break;
            case 5: start = insert_before(start);
                    break;
            case 6: start = insert_after(start);
                    break;
            case 7: start= delete_begin(start);
                    break;
            case 8: start = delete_end(start);
                    break;
            case 9: start = delete(start);
                    break;
            default: printf("\n Please neter  a valid input");
            }
    }while(option!=10);
}
