#include<stdio.h>
/*Author: Raghav Maheshwari.
This is a simple program to understand the concept of passing structures to functions
*/
//1.This is the program 1
typedef struct{
    int x;
    int y;
}point;
void display(int,int);
void main(){
    point p1 = {2,3};
    display(p1.x,p1.y);
}
void display(int a, int b){
    printf("The co-ordinates of the point are %d and %d",a,b);
}

//2. This is the second program
#include<stdio.h>
typedef struct{
    int x;
    int y;
}point;
void display(point p);
void main(){
    point p ={3,4};
    display(p);
}
void display(point p){
    printf("The co-ordinates of the position are %d annd %d",p.x,p.y);
}
