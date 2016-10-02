/*************************************************************************************************************************************************************************************
Name	: Indresh Kumar Gupta
Roll 	: B15317
Purpose	: IC-250 Assignment-04 Part-1 : To check paranthesis balance 
Date	: 6/09/16
***************************************************************************************************************************************************************************************/

#include"stack_library.h"

int main(){

	system("clear");
	
	char ch;

	//flag to status of an expression (1 : balanced and 2 : unbalanced)
	int flag;

	node *top = NULL, *exp = NULL;

	start : 
	flag = 1;
	printf("\nPlease enter the expression (or type 0 to exit) : \n");
	ch = getchar();

	if(ch == '0')
		return 0;

	while(ch != 10){
		exp = push(exp, ch);

		if(flag)
			top = push(top, ch);
			
		//if a closing bracket is detected then starts poping element till the first opening bracket is detected
		if(ch == ')' && flag){
			while(top->data != '('){
				top = pop(top);
				if(top == NULL){
					flag = 0;
					break;
				}

			}

			top = pop(top);
		
		}
	
		ch = getchar();
	}
	
	exp = stackRev(exp);

	while(top != NULL && flag){
			if(top->data == '(' || top->data == ')')
				flag = 0;
			top = top->next;
	}
	
	printf("Expression \"");
	display(exp);

	if(flag)
		printf("\" is having balanced parenthesis\n");
	else
		printf("\" is having unbalanced parenthesis\n");

	top = destroy(top);
	exp = destroy(exp);
	goto start;

	return 0;
}
