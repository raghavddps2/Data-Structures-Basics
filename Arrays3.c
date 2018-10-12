#include<stdio.h>
/* This contains may simple programs to get the basics of arrays right using pointers*/
void main(){
    int arr[] = {1,2,3,4,5};
    printf("Address of arrray= %d %d %d",arr,&arr[0],&arr); 
    //The above two blocks of code clearly depict that arr, arr[0], and arr will give the same result. Let us try and use %p also.
     printf("\nAddress of arrray= %p %p %p",arr,&arr[0],&arr);
     //Here, the thing taht is to be noted is that %p will give some hexadecimal value instead of the address in integer format

     //The following three codes accurately depicts how the post increment and pre incremnet kind of things work
     //in pointers.
    /*int arr[] = {10, 20}; 
    int *p = arr; 
    ++*p; 
    printf("arr[0] = %d, arr[1] = %d, *p = %d", arr[0], arr[1], *p); */


     /*int arr[] = {10, 20}; 
    int *p = arr; 
    *p++; 
    printf("arr[0] = %d, arr[1] = %d, *p = %d", arr[0], arr[1], *p); */

    /*int arr[] = {10, 20}; 
    int *p = arr; 
    *++p; 
    printf("arr[0] = %d, arr[1] = %d, *p = %d", arr[0], arr[1], *p); */

    //Now we have a code that will clear our understanding of pointers and arrays(One Dimensional)
    int arr2[]={1,2,3,4,5};
    int *ptr,i;
    ptr = &arr[2];
    *ptr  = -1;
    *(ptr+1) = 0;
    *(ptr -1) = 1;
    for(i=0;i<5;i++){
        printf("\n%d",*(arr+i)); //Note that *(arr+i) is same as *arr[i] or *i[arr] or *(i+arr);
    }
}
