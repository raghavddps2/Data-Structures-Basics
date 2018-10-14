/*
    @Author: Raghav Maheshwari
    This is a program depicting the arrays of structures...
*/
#include<stdio.h>
#include<string.h>
void main(){
    printf("\n-----Some Info----");
    printf("Enter the Number of students in the class");
    int n;
    scanf("%d",&n);
    struct student{
        int roll_no;
        char name[80];
        float fees;
        char DOB[20];
    };
    struct student stud[50];

    for(int i=0;i<n;i++){
        printf("\n----------------Enter the details of student %d---------------",i+1);
            printf("\nEnter your roll no\t");
            scanf("%d",&stud[i].roll_no);
            printf("\nEnter your name\t");
            scanf("%s",stud[i].name);
            printf("\nEnter the fees of the student\t");
            scanf("%f",&stud[i].fees);
            printf("\nEnter the date of birth of the student\t");
            scanf("%s",stud[i].DOB);
    }
    for(int i=0;i<n;i++){
        printf("\n----------------Details of student %d are---------------",i+1);
            printf("\nRoll No:\t%d",stud[i].roll_no);
            printf("\nName;\t%s",stud[i].name);
            printf("\nFees:\t%f",stud[i].fees);
            printf("\nDOB:\t%s",stud[i].DOB);
    }
    printf("\nEnter the num of student whose details are to be edited");
    int num;
    scanf("%d",&num);
    num = num-1;
        int roll_no;
        char name[80];
        float fees;
        char DOB[20];
            printf("\nEnter the new roll no\t");
            scanf("%d",&roll_no);
            printf("\nEnter the new name\t");
            scanf("%s",name);
            printf("\nEnter the new fees of the student\t");
            scanf("%f",&fees);
            printf("\nEnter the new date of birth of the student\t");
            scanf("%s",DOB);

            stud[num].roll_no = roll_no;
            strcpy(stud[num].name,name);
            stud[num].fees = fees;
            strcpy(stud[num].DOB,DOB);

    printf("\n----------------Edited Details of student are---------------");
            printf("\nRoll No:\t%d",stud[num].roll_no);
            printf("\nName;\t%s",stud[num].name);
            printf("\nFees:\t%f",stud[num].fees);
            printf("\nDOB:\t%s",stud[num].DOB);
}
