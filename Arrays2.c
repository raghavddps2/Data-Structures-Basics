#include<stdio.h>
/* The task of this program again is to read an array and then interchange the largest and the smallest values*/
void read_array(int arr[],int size);
void interchange(int arr[],int size);
int largest_array(int arr[],int size);
int smallest_array(int arr[],int size);
void display(int arr[],int size);
void main(){
    int num[100],size;
    printf("Enter the size of the array\t");
    scanf("%d",&size);
    read_array(num,size);
    interchange(num,size);
    display(num,size);
}

void read_array(int arr[],int size){
    for(int i=0;i<size;i++){
    printf("Enter element %d\t",i+1);
    scanf("%d",&arr[i]);
    }
}
void interchange(int arr[],int size){
    int large_pos = largest_array(arr,size);
    int small_pos = smallest_array(arr,size);
    int  temp = arr[large_pos];
    arr[large_pos] = arr[small_pos];
    arr[small_pos] = temp;
    printf("largest is %d",arr[large_pos]);
    printf("\nsmallest is %d",arr[small_pos]);
}
int largest_array(int arr[],int size){
    int largest_no = arr[0];
    int large_pos;
    for(int i=0;i<size;i++){
        if(arr[i]>largest_no){
            largest_no = arr[i];
            large_pos = i;
        }
    }
    return large_pos;
}
int smallest_array(int arr[],int size){
    int smallest_no = arr[0];
    int small_pos;
        for(int i=0;i<size;i++){
        if(arr[i]<smallest_no){
            smallest_no = arr[i];
            small_pos = i;
        }
    }
    return small_pos;
}
void display(int arr[],int size){
    printf("The lements of the array are");
    for(int i=0;i<size;i++){
        printf("\n%d",arr[i]);
    }
}
