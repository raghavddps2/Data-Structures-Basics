/* @Author: Raghav Maheshwari
This is the first program for structures. Basically in this program what we will learn is how to declare structures,
use them and accessing the member of the structure.
*/
#include<stdio.h>
void main(){
   struct student{
       int roll_no;
       char name[80];
       float fees;
       char DOB[80];
   }stud1;
   printf("---------------------Enter the details of the student name---------------------");
   printf("\nEnter your roll no\t");
   scanf("%d",&stud1.roll_no);
   printf("\nEnter your name\t");
   scanf("%s",stud1.name);
   printf("\nEnter the fees of the student\t");
   scanf("%f",&stud1.fees);
   printf("\nEnter the date of birth of the student\t");
   scanf("%s",stud1.DOB);
   printf("\n---------------------The details of the student are:---------------------");
   printf("\nRoll No:\t%d",stud1.roll_no);
   printf("\nName;\t%s",stud1.name);
   printf("\nFees:\t%f",stud1.fees);
   printf("\nDOB:\t%s",stud1.DOB);
}
