/*
    @Author: Raghav Maheshwari.
    Problem Statement: Write a program to read,display,add and subtract two distances.Distances must be defined in 
    Kms and metres.__x86_64
    */

   /*
     Please Note that this program doesn't pass certain validations like negative metres and converting 1000 metres to 
    one km and things, please don't consider that*/
   #include<stdio.h>
   #include<stdlib.h>
   
   typedef struct{
       int kms;
       int met;
   }distance;
   distance add_distance(distance,distance);
   distance sub_distance(distance,distance);
   void main(){
       int option;
       do{
           printf("\n-----------------Main Menu---------------");
           printf("\n1.Read the distances");
           printf("\n2. Display the distances");
           printf("\n3. Add the two distances");
           printf("\n4. Subtract the two distances");
           printf("\n5. Exit!!");
                
           printf("\nEnter your option");
           scanf("%d",&option);
            distance d1,d2,d3,d4;
           switch(option){
               case 1:
                    printf("\nEnter the distance 1, first enter the distance in kms and then in metres");
                    scanf("%d%d",&d1.kms,&d1.met);
                    printf("\nEnter the distance 2, first enter the dstance in kms and then in metres");
                    scanf("%d%d",&d2.kms,&d2.met);
                    break;
                case 2:
                    printf("\nThe display 1 is %d kms and %d metres",d1.kms,d1.met);
                    printf("\nThe distance 2 is %d kms and %d metres",d2.kms,d2.met);
                    break;
                case 3:
                    d3 = add_distance(d1,d2);
                    printf("The addition of distances 1 and distances 2 is %dkms and %d metres",d3.kms,d3.met);
                    break;
                case 4:
                    d4 = sub_distance(d1,d2);
                    printf("The subtraction of distance 1 and distance 2 is %d kms and %d metres ",d4.kms,d4.met);
                    break;
                case 5:
                    exit(0);
           }
       }while(option<6);
   }

   distance add_distance(distance d1, distance d2){
       distance d3;
       d3.kms = d1.kms + d2.kms;
       d3.met = d1.met + d2.met;
        return d3;
   }

    distance sub_distance(distance d1, distance d2){
       distance d4;
       d4.kms = d1.kms - d2.kms;
       d4.met = d1.met - d2.met;
        return d4;
   }
