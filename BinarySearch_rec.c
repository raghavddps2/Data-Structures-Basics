#include<stdio.h>

int binarySearch(int a[],int low,int high,int value){

    int mid = (low+high)/2;
    if(low>high){
        return 0;
    }
    else if(a[mid] == value){
        return 1;
    }
    else if(a[mid]>value){
        binarySearch(a,low,mid-1,value);
    }
    else{
        binarySearch(a,mid+1,high,value);
    }

}
void main(){
    int a[50],n;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);
    printf("\nEnter the elements:\t");
    for(int i=0;i<n;i++){
        printf("\nEnter element:\t");
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j+1];
                    a[j+1] = a[j];
                    a[j] = temp;
            }
        }
    }
/*  for(int i=0;i<n;i++){
    printf("%d\t",a[i]);
} 
    This program is used to print the values in a sorted order.
*/
    int x;
    printf("\nEnter the element you wanna search:\t");
    scanf("%d",&x);
    int flag = binarySearch(a,0,n,x);


    if(flag == 0){
        printf("\n Element not found");
    }
    else{
        printf("\nElement found!");
    }
}
