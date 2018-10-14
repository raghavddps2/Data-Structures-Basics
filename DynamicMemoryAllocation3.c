/* 
    Author: Raghav Maheshwari
    Problem Statement: This is a problem in which we will use the realloc function to reallocate the memory
                        and take the ful name of a person instead of the first name;
*/
#include<stdio.h>
#include<stdlib.h>
void main(){
    char *str;
    /*
        Here, the memory allocation occurs for 8 characters
    */
    str = malloc(8*sizeof(char));
    printf("Enter your first name");
    gets(str);
    printf("The first name is:\t");
    puts(str);
    /*
        Now, consider i want to enter my full name, so i will use the realloc() function to allocate
        more memory
    */
    str = realloc(str,20);
    printf("Enter your full name");
    gets(str);
    printf("The full name is:\t");
    puts(str);
    free(str); //The free() will deallocate the memory!!
}
