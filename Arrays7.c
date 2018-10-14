/*
@Author: Raghav Maheshwari
This program will contain stuff about Multidimensional arrays, basics are same as two D arrys, 
just a dimension is increased.

1. A program to read and display a three dimensional array using functions.
2. A program to read and display a three dimensional array using pointers.
*/
#include<stdio.h>
/*
This one represents the solution without pointers.
*/
void read_array(int array[3][3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                printf("Enter the array[%d][%d][%d]\t",i,j,k);
                scanf("%d",&array[i][j][k]);
            }
        }
    }
}
/*
This one represents the solution without pointers.
*/
void print_array(int array[3][3][3]){
        for(int i=0;i<3;i++){
            printf("Part %d\n\n",i);
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
               printf("%d ",array[i][j][k]);
            }
            printf("\n");
        }
    }
}
void print_array1(int (*array1)[2][2]){
    for(int i=0;i<2;i++){
            printf("Part %d\n\n",i);
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
               printf("%d ",*(*(*(array1+i)+j)+k));
            }
            printf("\n");
        }
    }
}
void main(){
    int array[3][3][3];
    read_array(array); //Without pointers
    print_array(array); //Without pointers

    int array1[2][2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                printf("Enter the array[%d][%d][%d]\t",i,j,k);
                scanf("%d",&array[i][j][k]);
            }
        }
    }
    print_array1(array1);
}

