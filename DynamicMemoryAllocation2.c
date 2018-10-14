/*
    @Author: Raghav Maheshwari
    This code is supposed to read an integer array and the print it.
*/

#include<stdio.h> //For all the functions we use like printf and scanf
#include<stdlib.h> //For usimg the dynamic memory allocation functions.
void main(){
    printf("Enter the size of the array");
    int n;
    scanf("%d",&n);
    int *arr = calloc(n,sizeof(int));
    /*
        The following block of code is executd if memory could not be allocated to tthe array

    */
    if(arr == NULL){
        printf("MEMORY CANNOT BE ALLOCATED");
        exit(0);
    }
    /*
        This was the dynamic memory declaration using the calloc function
        int *arr;
        arr = calloc(n,sizeof(int));
        This differs from malloc in the way that it initializes all the array values to zero.

    */
   for(int i=0;i<n;i++){
       printf("%d",arr[i]);
   }
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    free(arr);
}
