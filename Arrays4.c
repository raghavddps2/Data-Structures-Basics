#include<stdio.h>
/* This is a dumi program to revise how to work with two dimenzional arrays and functions*/
void read_matrix(int arr[10][10],int r);
void display_matrix(int arr[10][10],int r);
void main(){
    int arr[10][10];
    int r;
    printf("Enter the number of rows and columns in the matrix");
    scanf("%d",&r);
    read_matrix(arr,r);
    display_matrix(arr,r);
}

void read_matrix(int arr[10][10], int r){
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            if(i>j)
                arr[i][j] = 1;
            else if(i<j)
                arr[i][j] = -1;
            else
                arr[i][j] = 0;
        }
    }
}
void display_matrix(int arr[10][10],int r){
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
}
