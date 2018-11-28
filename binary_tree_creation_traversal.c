#include<stdio.h>
#include<conio.h>

struct node{
    struct node* prev;
    int data;
    struct node *next;
};

struct node *tree = NULL;
