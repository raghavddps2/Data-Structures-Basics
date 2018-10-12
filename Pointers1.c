#include<stdio.h>
#include<conio.h>
void sum2(int*,int*,int*); //THis is just to declare the function prototype.
//This is a program to explain the basics of pointers.
void main(){
   int x; //This is just a normal variable declaration
    printf("\nThe value of x is %d",x); //This is just to see what value it gives
    x = 10;

     int *p; //This represents a pointer declaration. The asterisk symbol is used to declare a pointer variable.
    /* Basically what a pointer does is,it points to the memory location of the variable*/
    printf("\nThe memory occupied by the integer variable is %d",sizeof(x));
    printf("\nThe memory occupied by the pointer variabel is %d",sizeof(p));
   

    p = &x; //This assigns the address of the variable x to the pointer p;
    
    printf("\nThe address of the variable x is %d",&x); //This is using tthe ampersnad operator;
    
    printf("\nThe value stored in the pointer variable is %d",p); //This gives the value stored in the pointer variable.
    
    printf("\nThe value pointed using the pointer is %d",*p); //This gives the value 10;

    // Now let us have a look at the memory occupied by different datatype of pointers
    char *ptr1;
    float *ptr2;
    double *ptr3;
    printf("\nThe size occupied by the character pointer is %d",sizeof(ptr1));
    printf("\nThe size occupied by the character pointer is %d",sizeof(ptr2));
    printf("\nThe size occupied by the character pointer is %d",sizeof(ptr3));
    //The size pointed is same, this shows that the pointer variable occupy the same memory irrespective of the datatype

    /* The following gives a nice description of pointer Arithmetic*/

    int num1=2, num2=3,num3=4,num4=5;
    int *ptra1;
    int *ptra2;
    int *ptra3;
    int* ptra4; //This shows that it is the same to declare pointers as int* ptr1 or int *ptr1;
    ptra1= &num1;
    ptra2= &num2;
    ptra3= &num3;/*All these four statements assign the address to the variables */
    ptra4 = &num4;
    // The following statemnets will depict the pointer arithmetic
    int sum = (*ptra1)+(*ptra2);
    (*ptra1)++;
    int diff = (*ptra1)-(*ptra2);
    int mul = (*ptra3)*(*ptra4);
    // The followingf four statements describe the difference between (*ptra4)++ and *ptra++ , ++ has higher preference
    (*ptra4); 
    printf("\nThe value of num4 is %d",*ptra4);
    printf("\nThe memory address of num4 is %d",&num4);
    *ptra4++;
    printf("\nThe memory address of num4 is %d",&num4); 
    printf("\nThe value of num4 is %d",*ptra4); //Why does that gives 4(GREAT CONFUSION);
    int div = (*ptra3)/(*ptra2);
    //The following four statements will give the value of the four variables created
    printf("\nThe value of sum is %d",sum);
    printf("\nThe value of diff is %d",diff);
    printf("\nThe value of mul is %d",mul);
    printf("\nThe value of div is %d",div);
    /* The folowing code is going to 
        depict the use of Null Pointer
        */
       int *pk =NULL;
       printf("\nThe memory location is %d",pk);
     //  printf("\nThe value pointed is %d",*pk); If you execute this statement, it will give a segmentation fault as
     // We are trying to access the memory location that is not accessible.
       //Assignig ptr = 0; inplies the smae as being a NULL pointer

       /* Generic Pointers: 
        This is undoubtedly one of the most coolest topic i have seen in pointers
        What generic pointer does is basically it has a void datatype and can point to any type of data
        type depending on whatever datatype we wnat it to point to.*/

        void *ptrg;
        int x1 = 12;
        char ch = 'A';
        ptrg = &x1;
        printf("\nThe value pointed by the generic pointer is %d",*(int*)ptrg);
        ptrg = &ch;
        printf("\nThe value pointed by the generic pointer is %c",*(char*)ptrg);

        //This clears the concept of generic pointers.

        /* Now in the following piece of code, we will learn as to how we can use the pointers in functions,
            This is a simple function to calculate the sum of two numbers using functions and pointers*/
            int a = 10, b=20;
            int total;
            sum2(&a,&b,&total);
            printf("\nThe sum is %d",total);

        /* The following code will depict how pointers point to ppointers and their dereferncing*/
        int k =12;
        int *p4,**p5;
        p4 = &k;
        p5 = &p4;
        printf("\nThe value of k is %d",**p5);

/* The following block of code will clear a very basic doubt i had */
int c=20;
int *pc1;
pc1 = &c;
//int pc1 =10;
//printf("\nValue of c is %d",*pc1);
//printf("\nThe value of the variable p is %d",pc1);

    /* If you execute the above two lines of code, it will give an error, that there is a redeclarartion of variable p1,
    but there is one interesting thing to note here, what the conpiler treats is it fist sees the variabel p1...This is some
    thing unsual, as mydhili ma'am about it.*/
    int numl1 =10;
    int numl2 =20;
    int *ptrl1;
    int *ptrl2;
    ptrl1 = &numl1;
    ptrl2 = &numl2;
   // printf("%d",ptr2-ptr1); 
   /* The above statement will not work, this works in the case of an array as it points to consecutive memory
    locations.*/
    int arr[3]={0,1,2};
    int *ptrk1 = arr;
    int *ptrk2 = arr+2;
    printf("\nThe value is %d",ptrk2-ptrk1);

    /*This again displays a very interesting fact, that we can directly do pointer subtarction or arithmetic in
        in general in case of arrays, as it points to the consecutive memory locations.*/

}
void sum2(int *a1,int *a2,int *t){
    *t = *a1 + *a2;
}
