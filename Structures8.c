/*
    @Author: Raghav Maheshwari
    Problem Statement: Write a program, using an array of pointers to a structure, to read and display the data of students.
*/

//Logically this is to be done using the dynamic memory managemnet functions like malloc, callor or realloc but as i don't know
//any of these yet, so done without them,
#include<stdio.h>
struct student{
    int roll_no;
    char name[20];
    char course[20];
    float fees;
};
struct student *ptr_stud[10];
struct student stud[10];
void main(){
    int i,n;
    printf("Enter the number of students");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        //ptr_stud[i] = (struct student *)(malloc(sizeof(struct student)));
        //Even the above statement can be used this will do the work without declaring the stud structure.
        ptr_stud[i] = &stud[i];
        printf("\n---------------Enter the details of the student %d-------------",i+1);
        printf("\nEnter the roll number of the student:\t");
        scanf("%d",&ptr_stud[i]->roll_no);
        printf("\nEnter the name of the student:\t");
        scanf("%s",ptr_stud[i]->name);
        printf("\nEnter the course in which student is enrolled:\t");
        scanf("%s",ptr_stud[i]->course);
        printf("\nEnter the fees of the course:\t");
        scanf("%f",&ptr_stud[i]->fees);
    }

        for(int i=0;i<n;i++){
            printf("\n--------------The details of the student %d are------------",i+1);
            printf("\nThe roll no of the student is:\t %d",ptr_stud[i]->roll_no);
            printf("\nThe name of the student is :\t%s",ptr_stud[i]->name);
            printf("\nThe course of the student is :\t%s",ptr_stud[i]->course);
            printf("\nThe fees of the course is :\t%f",ptr_stud[i]->fees);
    }
}
