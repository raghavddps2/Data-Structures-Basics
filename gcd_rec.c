#include<stdio.h>
//This is a program to calculate the GCD of two numbers.
int gcd(int,int);
void main(){
    printf("\nProgram to calculate the GCD of two numbers");
    printf("\n**************************************");
    int x1,x2;
    printf("\nEnter the first number:\t");
    scanf("%d",&x1);
    printf("\nEnter the second number:\t");
    scanf("%d",&x2);

    int val = gcd(x1,x2);
    printf("\nThe GCD of the given two numbers is %d",val);
}

int gcd(int x1,int x2){
   int rem = x1%x2;
    if(rem == 0){
        return x2;
    }
    else{
        gcd(x2,rem);
    }
}
