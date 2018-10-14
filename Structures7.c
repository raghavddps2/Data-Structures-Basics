/*
    Author: Raghav Maheshwari
    Problem Statement: Write a program to initialize the members of the structure by using pointer to the structure.
*/
#include<stdio.h>
struct student{
    int roll_no;
    char name[20];
    char course[20];
    float fees;
};
void main(){
    struct student stud1, *ptr_stud1;
    ptr_stud1 = &stud1;
    printf("\n---------------Enter the details of the student-------------");
    printf("\nEnter the roll number of the student:\t");
    scanf("%d",&ptr_stud1->roll_no);
    printf("\nEnter the name of the student:\t");
    scanf("%s",ptr_stud1->name);
    printf("\nEnter the course in which student is enrolled:\t");
    scanf("%s",ptr_stud1->course);
    printf("\nEnter the fees of the course:\t");
    scanf("%f",&ptr_stud1->fees);

    printf("\n--------------The details of the student are------------");
    printf("\nThe roll no of the student is:\t %d",ptr_stud1->roll_no);
    printf("\nThe name of the student is :\t%s",ptr_stud1->name);
    printf("\nThe course of the student is :\t%s",ptr_stud1->course);
    printf("\nThe fees of the course is :\t%f",ptr_stud1->fees);



}

