#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/* This is also a sample program in which we are learning how to use a structure and use it to perform some operations on 
    complex numbers*/
void main(){
    struct complex{
        int real;
        int img;
    };
    struct complex c1,c2,sum,sub;
    int option;
    do{
        printf("\n-----------Main Menu---------");
        printf("\n1. Read the complex number");
        printf("\n2. Display the complex Numbers");
        printf("\n3. Add the complex Numbers");
        printf("\n4. Subtract the complex Numbers");
        printf("\n5. Exit!");
        printf("\nEnter your choice\t");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("\nEnter the real and imaginary part of the complex number 1\t");
                scanf("%d%d",&c1.real,&c1.img);
                printf("\n Enter the real and imaginary part of the complex number 2\t");
                scanf("%d%d",&c2.real,&c2.img);
                break;
            case 2:
                printf("\n The complex number 1 is %d+i%d",c1.real,c1.img);
                printf("\n The complex number 2 is %d+i%d",c2.real,c2.img);
                break;
            case 3:
                sum.real = c1.real+c2.real;
                sum.img = c1.img + c2.img;
                printf("\n The Addition of two complex numbers is %d+i%d",sum.real,sum.img);
                break;
            case 4:
                sub.real = c1.real - c2.real;
                sub.img = c1.img - c2.img;
                printf("\n The subtraction of two complex numbers is %d+i%d",sub.real,sub.img);
                break;
            case 5:
                exit(0);
                
        }
    }while(option<6);






}
