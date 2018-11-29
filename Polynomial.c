#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff; //coefficient of the term of polynomial
    int expo; //expoment (Power of x)
    struct node *next;
};
struct node *start = NULL;
struct node *start1 = NULL; //For the first polynomial
struct node *start2 = NULL; //For the second polynomial
struct node *start3 = NULL; // For the third polynomail
struct node *ptr = NULL;


// Creates the polynomial we want. Gets out when the value is -1.
struct node *createPoly(struct node *ptr){
        struct node *ptr1;
        ptr1 = ptr;
        int coeff;
        int expo;

        printf("\nEnter the Coefficient of the First term:\t");
        scanf("%d",&coeff);
        printf("\nEnter the exponent of the first term:\t");
        scanf("%d",&expo);

        while(coeff != -1){

            if(ptr1 == NULL){
                struct node *new_Node = (struct node*)malloc(sizeof(struct node));
                new_Node->coeff = coeff;
                new_Node->expo = expo;
                new_Node->next= NULL;
                ptr1 = new_Node;
                ptr = new_Node;
            }
            else{
                    ptr1 = ptr;
                    while(ptr1->next != NULL){
                        ptr1 = ptr1->next;
                    }
                 struct node *new_Node = (struct node*)malloc(sizeof(struct node));
                 new_Node->coeff = coeff;
                 new_Node->expo = expo;
                 new_Node->next = NULL;
                 ptr1->next = new_Node;     
            }
                printf("\nEnter the Coefficient of the next term:\t");
                scanf("%d",&coeff);
                if(coeff == -1){
                    break;
                }
                printf("\nEnter the exponent of the next term:\t");
                scanf("%d",&expo);
            
        }
        return ptr;
}
// Supporting function for the addPoly function. Helps in creating the third list!
struct node *addNode(struct node *start,int val,int expo){
    struct node *ptra;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(start == NULL){
        
        newNode->coeff = val;
        newNode->expo = expo;
        newNode->next = NULL;
        start = newNode;
    }
    else{

        ptra = start;
        while(ptra->next != NULL){
            ptra = ptra->next;
        }
        newNode->coeff = val;
        newNode->expo = expo;
        newNode->next = NULL;
        ptra->next = newNode;
    }

    return start;
}

//Function to display the individual and sum of polynomials.
void displayPoly(struct node *ptr){
    struct node *ptr2 = ptr;
    while(ptr2 != NULL){
        if(ptr2->next != NULL){
            printf("%dx^%d + ",ptr2->coeff,ptr2->expo);
            ptr2 = ptr2->next;
        }
        else{
            printf("%dx^%d ",ptr2->coeff,ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
}

//Function to add the polynomials.
struct node *addPoly(struct node *start3,struct node *start1,struct node *start2){
    struct node *ptr1 = start1;
    struct node *ptr2 = start2;
        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1->expo == ptr2->expo){ //Same Expo!
                start3 = addNode(start3,ptr1->coeff+ptr2->coeff,ptr1->expo);
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if(ptr1->expo < ptr2->expo){ //Greater expo for poly 2
                start3 = addNode(start3,ptr2->coeff,ptr2->expo);
                ptr2 = ptr2->next;
            }
            
            else if(ptr1->expo > ptr2->expo){ //Greater expo for poly 1
                start3 = addNode(start3,ptr1->coeff,ptr1->expo);
                ptr1 = ptr1->next;
            }
        }

        if(ptr1 == NULL){
            while(ptr2 != NULL){
                start3 = addNode(start3,ptr2->coeff,ptr2->expo);
                ptr2 = ptr2->next;
            }
        }
        
        if(ptr2 == NULL){
            while(ptr1 != NULL){
                start3 = addNode(start3,ptr1->coeff,ptr1->expo);
                ptr1 = ptr1->next;
            }
        }
        return start3;
}
//Function to display the menu.
void displayMenu(){
    printf("\n------------------------------------------------------");
    printf("\n1. Create the polynomial 1");
    printf("\n2. Display the polynomial 1");
    printf("\n3. Create the polynomial 2");
    printf("\n4. Display the polynomial 2");
    printf("\n5. Add the two polynomials and Dsiplay the result.");
    printf("\n6. EXIT!");
    printf("\n------------------------------------------------------");
}
//Menu driven main program.
int main(){
    
    int choice;
    displayMenu();
    printf("\nEnter your choice:\t");
    scanf("%d",&choice);
    while(choice != 6){
        switch(choice){
            case 1:
                    printf("\nEnter the polynomial 1:\t");
                    start1 = createPoly(start1);
                    break;
            
            case 2:
                    printf("\nThe polynomial 1 is:\t");
                    displayPoly(start1);
                    break;
            
            case 3:
                    printf("\nEnter the polynomial 2:\t");
                    start2 = createPoly(start2);
                    break;

            case 4:
                    printf("\nThe Polynomial 2 is:\t");
                    displayPoly(start2);
                    break;
            
            case 5:
                    start3 = NULL; //This line is very important. Try removing the line and see the output when Add button is pressed twice!
                    start3 = addPoly(start3,start1,start2);
                    printf("\nThe addition of the two polynomial is:\t");
                    displayPoly(start3);
                    break;
            
            default:
                    printf("\nInvalid choice");
                    break;
        }
        displayMenu();
        printf("\nEnter your choice:\t");
        scanf("%d",&choice);
    }
}
