#include<stdio.h>
#include<stdlib.h>
/*In this program to learn  the basics of arrays using functions and pointers what my startegy is to learn how 
    to use arrays in functions and use pointers alongside*/

// 1. The first task i am doing is to take an array and find the smallest number in an array.
void read_array(int arr[],int size);
int smallest_array(int arr[],int size);
void main(){
    int num[10];
    printf("Enter the size of the array");
    int size;
    scanf("%d",&size);
    read_array(num,size);
   /*  for(int i=0;i<size;i++){
        printf("\n%d",num[i]);
    } */ 
    //The above block pf code tells us that the values are assigned to num as well, i know might seem quite obvious.
   
   printf("The samllest value in the array is %d",smallest_array(num,size));
}
//The function below is for task1...
void read_array(int arr[],int size){

    for(int i=0;i<size;i++){
    printf("Enter the array\t");
    scanf("%d",&arr[i]);
    }
}
//The function below ia agin for task1
int smallest_array(int arr[],int size){
    int small = arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]<small)
            small = arr[i];
    }
    return small;
}
