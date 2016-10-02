/*************************************************************************************************************************************************************************************
Name	: Indresh Kumar Gupta
Roll 	: B15317
Purpose	: Program to perform stack operations 
************************************************************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

//node for linked list
typedef struct node{												
	struct node* next;
	char data;
}node;

node* push(node* top, char data);
node* pop(node* top);
int count(node* top);
node* stackRev(node* top);
node* destroy(node* top);
void display(node* top);
