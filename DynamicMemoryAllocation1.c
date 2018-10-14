/*  
    @Author: Raghav Maheshwari
    Memory allocation in C programs
    Problem statement: In this program i am going to read and display an array using
                        Dynamic memory allocation functions.
*/

#include<stdio.h>
#include<stdlib.h>
void main(){
    int *arr;
    int n;
    printf("Enter the value of n");
    scanf("%d",&n);
    arr = (int *)malloc(n*sizeof(int));
    /*
        The following block of code is executd if memory could not be allocated to tthe array

    */
    if(arr == NULL){
        printf("MEMORY CANNOT BE ALLOCATED");
        exit(0);
    }
    /*
        This represents how malloc function is used in the program for allocating the memory in the heap
        The syntax for doing so is very very simple
        int *arr = malloc(n*sizeof(int));
        arr = (int *)malloc(n*sizeof(int));
        
        Both the statements are equally valid...
        This will print the initial values as junk!!

    */
      for(int i=0;i<n;i++){
       printf("%d  ",arr[i]);
   }
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
