//@Author: Raghav Maheshwari
/*
    This program will help me to understand how to use pointers in two-dimensional array, what
    double pointers which seem to be working well, doesn't work and all
*/
#include<stdio.h>
void absolute_memory_basics();
void absolute_basics_printing();
void printing(int arr[10][10]);
void main(){
   absolute_memory_basics();
    /* Now  we have an important thing to look out at, the addresses in two dimensional arrys
    work the same as one dimensional arrays.*/
    absolute_basics_printing();
}
void absolute_memory_basics(){
    int mat[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int *ptr1;
    ptr1 = &mat[0][0];
    //Lets have a look at the memory distribution
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            printf("Address is %d",&mat[i][j]);
            printf("\n");
        }
    }
    printf("_____________________New Era Starts___________________\n");
    int arr[5]={1,2,3,4,5};
    int *ptr;
    ptr = &arr[0];
    printf("Address is %d\n",&arr[0]);
    printf("Address is %d\n",ptr);
   // printf("Value pointed is %d\n",*ptr);
//The above block of code prints the address of all the lements of the array.
//Now lets look what does ptr1 prints
printf("Address of first elemnet of first row is %d",&mat[0][0]);
printf("Address of first elemnet of first row is %d",&mat);   
printf("Addresss is %d",ptr1);
printf("value pointed is %d",*ptr1);
}
void absolute_basics_printing(){
    int arr[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            arr[i][j] = i+j;
        }
    }
    printing(arr);
}
void printing(int arr[10][10]){
        for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
           printf("%d ", arr[i][j]); 
        }
        printf("\n");
    }
}
