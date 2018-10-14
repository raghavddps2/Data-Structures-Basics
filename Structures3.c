#include<stdio.h>
void main(){
    struct DOB{
        int day;
        int month;
        int year;
    };
    struct student{
        int roll_no;
        char name[80];
        float fees;
        struct DOB date;
    };
    struct student stud1;
     printf("---------------------Enter the details of the student name---------------------");
   printf("\nEnter your roll no\t");
   scanf("%d",&stud1.roll_no);
   printf("\nEnter your name\t");
   scanf("%s",stud1.name);
   printf("\nEnter the fees of the student\t");
   scanf("%f",&stud1.fees);
   printf("\nEnter the date of birth\t");
   scanf("%d%d%d",&stud1.date.day,&stud1.date.month,&stud1.date.year);
   printf("\n---------------------The details of the student are:---------------------");
   printf("\nRoll No:\t%d",stud1.roll_no);
   printf("\nName;\t%s",stud1.name);
   printf("\nFees:\t%f",stud1.fees);
   printf("\nDOB:\t%d/%d/%d",stud1.date.day,stud1.date.month,stud1.date.year);
}
