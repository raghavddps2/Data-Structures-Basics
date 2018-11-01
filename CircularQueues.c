#include<stdio.h>
#include<conio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

/*
    We came with the concept of circular queuessimply because memory was being wasted in linear queue.
*/

void enqueue(int element){
    // Added the statement (front == rear + 1), this statement arrives as vijay told...
    if((front==0 && rear == MAX-1) || (front == rear +1))
        printf("\nOVERFLOW");
    else if(front == -1){
            front =0;
            rear =0;
            queue[rear]=element;
        }
    else if((front != 0) && (rear == MAX-1) ){
                rear =0;
                queue[rear] = element;
    }
    else{
        rear++;
        queue[rear] = element;
    }
}
/* Function to enter element into a circular queue */

int dequeue(){
    int val;
    if(front == -1){
        printf("\nUNDERFLOW");
        return -1;
    }
    else if(front == rear){
        val = queue[front];
        front = rear = -1;
        return val;
    }
    else if(front == MAX-1){
        val = queue[front];
        front =0;
        return val;
    }
    else{
        val = queue[front];
        front++;
        return val;
    }
    
}
int peak(){
    if(front == -1){
        printf("\nQueue is empty");
        return -1;
    }
    else{
        return queue[front];
    }
}
void display(){
    if(front == -1){
        printf("\nQueue is empty");
    }
    else if(rear>=front){
        printf("\nThe elements are: \t");
        for(int i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }
    else{
        printf("\nThe elements are: \t");
        for(int i=front;i<MAX;i++){
            printf("%d\t",queue[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
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
                    if(num2 != -1){
                    printf("\nThe element dequeued id %d",num2);
                    }
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
     //printf("Hi");(Show break takes outside of while loop)
}
