/*************************************************************************************************************************************************************************************
Name	: Indresh Kumar Gupta
Roll 	: B15317
Purpose	: Program to perform stack operations 
***************************************************************************************************************************************************************************************/
#include"stack_library.h"

//pushes data in the stack
node* push(node* top, char data){											

	node* new = (node*)malloc(sizeof(node));
	new->data = data;

	if(top == NULL){
		top = new;
		top->next = NULL;
	}
	else{
		new->next = top;
		top = new;
	}

	return top;
}

//pops top element from stack
node* pop(node* top){		

	node* tmp;
	if(top != NULL){
		tmp = top;
		top = top->next;
		free(tmp);
	}

	return top;
}

//counts no. of elements in stack
int count(node* top){
	int n = 0;
	node* tmp = top;

	while(tmp != NULL){
		n++;
		tmp = tmp->next;
	}

	return n;
} 

//converts stack into queue by inverting the stack
node* stackRev(node* top){
	node* alt_top = NULL;

	while(top != NULL){
		
		alt_top = push(alt_top, top->data);
		top = top->next;
	}

	return alt_top;
}

//Destroys the whole stack at once
node* destroy(node* top){			

	while(top != NULL)
		top = pop(top);
	
	return top;
}

//Displays the elements in stack
void display(node* top){							
	
	node* tmp = top;

	while(tmp != NULL){
		printf("%c", tmp->data);
		tmp = tmp->next;
	}
}
