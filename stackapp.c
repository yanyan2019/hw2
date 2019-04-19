/* stackapp.c: Stack applcation */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"
/*************************************************
 * Using tack to check for unbalanced parentheses.
 **************************************************/

/* returns the next character if the string, once reaches end return '0'(zero)
 * 	param: s pointer to a string
 *	pre: s is not null
 */
char nextChar(char *s){
	static int i = -1;
	char c; 
	++i;
	c = *(s+i);
	if( c == '\0'){
		return '\0';
	}else
		return c;
}	

/* checks whether the (), {}, and [] are balanced or not
 * 	param: s pointer t oa strinf
 * 	PRE: S is not null
 * 	post: 
 */
int isBalanced(char *s){
	char ch;
	char ts;
	int b = 1;
		
	DynArr* stack;
	stack = newDynArr(5);

	if(s && strlen(s)){
		while(1){
			ch = nextChar(s);
			if(ch == 0 || ch == '\0'){
				break;
			}
		
			if(ch == '(' || ch == '[' || ch == '{'){
				pushDynArr(stack, ch);
			}else{
				if(ch == ')' || ch == ']' || ch == '}'){
					if(stack->size > 0){
						ts = getDynArr(stack, stack->size-1);
						printf("ts = %c, ch = %c\n",ts, ch);
						if((ts == '(' && ch  == ')') || (ts == '[' && ch == ']') || ts == '{' && ch  == '}' ){
							popDynArr(stack);
						}else{
							b = 0;
							break;
						}
					}else{
						b = 0;
						break;
					}
				}
			}
		}
	}
	if(stack->size > 0 && (ch == 0 || ch == '\0')){ /* check if any open parentheses left in stack when string ends*/
		b = 0;
	}

	if(stack != NULL)
		deleteDynArr(stack);

	return b;
}

int main(int argc, char* argv[]){
	char * s = argv[1];
	int res;

	printf("Assignment 2\n");
	
	if(argc == 2){
		res = isBalanced(s);
		if(res){
			printf("The string %s is balanced\n", s);
		}else{
			printf("The String %s is not balanced\n", s);
		}
	}
	else{
		printf("Please enter a string to  be evaluated.\n");
	}
	return 0;
}
