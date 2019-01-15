#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>


struct queue{
    int data;
    struct queue *next;
};
struct queue *front = NULL;
struct queue *rear = NULL;

void enqueue(int val){
    struct queue *ptr;
    ptr = (struct queue*)malloc(sizeof(struct queue));
    ptr->data = val;
    ptr->next = NULL;

    if(rear == NULL){
        rear = ptr;
        front = ptr;
        return;
    }
    rear->next = ptr;
    rear = ptr;
}

int dequeue(){
    struct queue *ptr;
    int temp;
    ptr = (struct queue*)malloc(sizeof(struct queue));
    ptr = front;
    if(front == NULL){
        printf("\nQueue is empty!");
        return 0;
    }
    temp = front->data;
    front = front->next;
    return temp;
    
}
int peak(){
    if(front == NULL){
        return -1;
    }
    else{
        return (front->data);
    }
}
void display(){
    struct queue *ptr;
    ptr = (struct queue*)malloc(sizeof(struct queue));
    if(front == NULL){
        printf("\nQueue is empty!");
    }
    else{
        ptr = front;
        printf("\nThe elements of the queue are;\t");
        while(ptr != (rear->next)){
                printf("%d  ",ptr->data);
                ptr = ptr->next;
        }
    }
}


void main(){
    int option,val;
    do{
        printf("\n******************Menu!**************");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Peak");
        printf("\n4.Display");
        printf("\n5.Exit!");

        printf("\nEnter your choice:\t");
        scanf("%d",&option);

        switch(option){
            case 1:
                    printf("\nEnter the element you wanna enqueue:\t");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2:
                    val = dequeue();
                    if(val != 0){
                        printf("\nThe element dequeud is %d",val);
                    }
                    break;
            case 3:
                    val  = peak();
                    if(val != -1){
                        printf("\n The elemenet at the peak is %d",val);
                    }
                    else{
                        printf("\nQueue is empty!");
                    }
                    break;
            case 4:
                    display();
                    break;
            case 5:
                    break;
            default:
                    printf("\nInvalid chocie!");
        }
    }while(option != 5);
}
