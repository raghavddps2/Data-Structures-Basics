#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL;
struct node *tree = NULL;

struct node *createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void createLeaf(struct node *root){

    int data;
    if(root == NULL){
        printf("\nEnter the value of the root element:\t");
        scanf("%d",&data);
        root = createNode(data);
        tree = root;
        return;
    }
    printf("\nEnter the data:\t");
    scanf("%d",&data);

    while(1){
        if(data >= root->data && root->right != NULL){
            root = root->right;
        }
        else if(data < root->data && root->left != NULL){
            root = root->left;
        }
        else{
            break;
        }
    }
    if(data >= root->data){
        root->right = createNode(data);
    }
    else{
        root->left = createNode(data);
    }
}

void inOrderTraversal(struct node *root){
    if(root!= NULL){
        inOrderTraversal(root->left);
        printf("%d  ",root->data);
        inOrderTraversal(root->right);
    }
}
void preOrderTraversal(struct node *root){
    if(root != NULL){
        printf("%d  ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct node *root){
    if(root != NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d  ",root->data);
    }
}

void main(){
    while(1){
        printf("\n1. Insert into the Tree");
        printf("\n2. Serach in the tree");
        printf("\n3. Print the three traversals");
        printf("\n4. EXIT!");
        int ch;
        printf("\nEnter your choice:\t");
        scanf("%d",&ch);


        switch(ch){
            case 1:
                    printf("\nInserting...");
                    createLeaf(tree);
                    printf("\ninserted Successfully");
            case 2:
                    printf("\nTo be implemented yet!");
                    break;
            case 3:
                    printf("\nPreOrderTraversal:\t");
                    preOrderTraversal(tree);

                    printf("\ninOrderTraversal:\t");
                    inOrderTraversal(tree);

                    printf("\nPostOrderTraversal:\t");
                    postOrderTraversal(tree);
                    break;

            case 4:
                    exit(0);
                    break;
            default:
                    printf("INVALID CHOICE!");
        }
    }
}
