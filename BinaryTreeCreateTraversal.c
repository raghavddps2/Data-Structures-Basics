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
    if(data == -1){
        return NULL;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}

void createTree(struct node *root){

    int data;
    if(root == NULL){
        printf("\nEnter the value of the element(root):\t");
        scanf("%d",&data);
        root = createNode(data);
        tree = root;
    }
        printf("\nThe value of the root element is %d",root->data);

        printf("\nEnter the value of the left child.Enter -1 to put NULL:\t");
        scanf("%d",&data);
        root->left = createNode(data);

        printf("\nEnter the value of the right child. Enter -1 to put NULL:\t");
        scanf("%d",&data);
        root->right = createNode(data);


    if(root->left != NULL){
        createTree(root->left);
    }
    if(root->right != NULL){
        createTree(root->right);
    }
}

void inOrderTraversal(struct node *root){
    if(root != NULL){
    preOrderTraversal(root->left);
    printf("%d  ",root->data);
    preOrderTraversal(root->right);
    }
}

void PreOrderTraversal(struct node *root){
    if(root != NULL){
    printf("%d  ",root->data);
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
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
    printf("\nCreating the tree...");
    createTree(tree);
    printf("\nTree created successfully");
    printf("\nInOrderTraversal:\t");
    inOrderTraversal(tree);
    printf("\nPreOrderTraversal:\t");
    preOrderTraversal(tree);
    printf("\nPostOrderTraversal:\t");
    postOrderTraversal(tree);
}
