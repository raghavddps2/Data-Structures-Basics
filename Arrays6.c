/*@Author: Raghav Maheshwari
    In this program i am hgoing to use double pointers to learn that they cannot be used in 2D arrrays.
    Next, we will execute a simple program to read and display a 2X2 Matrix.*/

#include<stdio.h>
void print_array(int (*arr)[2]);
void func_check_memory(){
        int arr[2][2] = {{1,2},{3,4}};
    int **ptr2;
    int *ptr1;
    ptr1 = &arr[0];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("Address is %d\n",&arr[i][j]);
            printf("\n");
        }
    }
    printf("Value of address stored in ptr1 is %d\n",ptr1);
    printf("Value pointed is %d\n",*ptr1);
}
void main(){
    int arr[2][2];
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            arr[i][j] = i+j;
        }
    }
    print_array(arr);
    func_check_memory();


    int array[][6]={{0,0,0,0,0,0},{0,0,0,0,0,16},{0,0,0,0,0,56}};  //Again a very important point to be considered
    //Not giiving the row size is valid whereas not giving the column size results in an error.s
    int i=2;
    int j= 5;
    printf("%d",*(*(array+i)+j));
    printf("\n%d",*(array[i]+j));

}
void print_array(int (*arr)[2]){
    /*What this does is basically, it declares ptr as the pointer to an array
        of 10 integers.
        The furthur subscript indicates the values furthur...*/
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
/*So, commenting things out.
    arr[i][j] is the very same as *(*(arr+i)+j) or *(arr[i]+j);
    This is very important and is to be remembered.*/

    /* Again lets practise passing the array and then using
        func(array);
        void func(int(*array)[3]);
        {
            printf("%d",*(*(array+i)+j));
            or
            printf("%d",*(array[i]+j));
        }*/
}
