#include<stdio.h>
void toh(int n,char source,char temp,char destination){
    if(n == 1){
        printf("\nMove disk %d from %c to %c",n,source,destination);
    }
    else{
        toh(n-1,source,destination,temp);
        printf("\nMove disk %d from %c to %c",n,source,destination);
        toh(n-1,temp,source,destination);
    }
}

void main(){
    printf("\n****************************************************");
    printf("\nThis program is to calculate the moves in tower_of_hanoi");
    int n;
    printf("\nEnter the number of disks:\t");
    scanf("%d",&n);
    toh(n,'A','B','C');
}
