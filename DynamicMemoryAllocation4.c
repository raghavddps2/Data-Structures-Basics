/*
    @Author: Raghav Maheshwari
    Problem Statement: Reading and displaying a two dimensional array...
*/
/*P.S:This is done for the rows dynamically, why that works with int also is 
unclear, this program is not still clear to me, as to how the dynamic memory allocation ocured*/
#include<stdio.h>
#include<stdlib.h>
void main(){
    int **arr;
    int r,c;
    printf("\nEnter the number of rows");
    scanf("%d",&r);
    printf("\nEnter the number of columns");
    scanf("%d",&c);
    arr = malloc(r*sizeof(int *)); //This is done for the rows dynamically, why that works with int also is 
    //unclear, this program is not still clear to me, as to how the dynamic memory allocation ocured
    for(int i=0;i<r;i++){
        arr[i] =malloc(c*sizeof(int)); //This is done for the columns of each row
    }
    printf("\nEnter the elements of the array\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("The elements of the array are\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

}
