#include<stdio.h>
#include<conio.h>
#define MAX 100

int front = -1;
int rear = -1;
int queue[MAX];

/* 
    Function to enqueue an element into the queue
*/
void enqueue(int element){
    if(rear == MAX-1){
        printf("\nOVERFLOW");
    }
    else if(front == -1){
        front =0;
        rear =0;
        queue[rear] = element;
    }
    else{
        rear++;
        queue[rear] = element;
    }
}

/*
    Function to dequeue an eleemnt from the queue
*/
int dequeue(){
    int val;
    if(front == -1){
        printf("\nUNDERFLOW");
        val = -1;
    }
    else if(front == rear){
        val = queue[front];
        front = rear =-1;
    }
    else{
        val = queue[front];
        front++;
        
    }
    return val;
}
/*
    Function to display the elements of the quueue
*/
void display(){
    if(front == -1){
        printf("\nThe queue is empty");
    }
    else{
        printf("\nThe elements of the queue are:\t");
        for(int i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }
}
/*
    Function to show the first element of the queue
*/
int peak(){
    if(front == -1){
        printf("\nQueue is empty");
        return -1;
    }
    else{
        return queue[front];
    }
}

void main(){
    int option;
    do{
        printf("\n**************************MENU***********************");
        printf("\n1. ENQUEUE");
        printf("\n 2. DEQUEUE");
        printf("\n 3. PEAK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT!");

        printf("\nEnter your choice:\t");
        scanf("%d",&option);
        int num1,num2,num3;
        switch(option){
            case 1:
                
                printf("\nEnter the element you wanna enqueue:\t");
                scanf("%d",&num1);
                enqueue(num1);
                break;
            case 2:
                    num2 = dequeue();
                    printf("\nThe element dequeued id %d",num2);
                    break;
            case 3:
                    num3 = peak();
                    if(num3 != -1){
                        printf("\nThe element at the peak is %d",num3);
                    }
                    break;    
            case 4:
                    display();
                    break;
            case 5:
                    break;
            default:
                    printf("\nINVALID CHOICE");
        
        }
    }while(option != 5);
}
