#include<stdio.h>
/*This is a program to calculate whether the number is an even number or an odd number using functions*/
/* As we have defined the functions below the main function, we should logically give the function declaration here*/
void NumberChecker_val(int); //Function prototype for call by value
void NumberChecker_ref(int*); // Function prototype for call  by reference
void main(){
int a;
printf("\nenter any number of your choice:\t");
scanf("%d",&a);
//Now this function will tell whether the number is odd or even(Call by value);
NumberChecker_val(a);
printf("\nThe value of a after the function call is %d",a);
//Now this function will again tell whether the number entered is an even or odd number(Call by reference);
NumberChecker_ref(&a);
printf("\nThe value of a after the function call is %d",a);
}
//This is a function using the call by value method 
void NumberChecker_val(int a){
    if(a%2 == 0){
        printf("\nThe entered number is an even number");
    }
    else{
        printf("\nthe entered number is an odd number");
    }
    /*The following statement simply increments the value of a 
    and tries to show that the value of a is remained unaffected*/
    a=a+10;
    printf("\nThe value of a inside the function is %d",a);
}
//This is a function using the call by reference method
void NumberChecker_ref(int *a){
    if (*a%2 == 0){
        printf("\nThe number entered is an even number");
    }
    else{
        printf("\nthe number entered is an od number");
    }
    /* The following statemnet simply increments the value of a and 
    tries to depict the importance of calll by reference*/
    *a = *a + 10;
    printf("\nThe value of a inside the function is %d",*a);
}

