//RPN, Reverse Polish notation
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct 
{
	ElemType data[MAXSIZE];
	int top;
} SqStack;

SqStack* createRPN(char s[])
{
	SqStack opstk, *rpn;   // opstk is operator stack, rpn is reverse Plish notation which is return value of this function.
	int i = 0;
	rpn = (SqStack *)malloc(sizeof(SqStack));
	opstk.top = rpn->top = -1;

	while(s[i] != '\0' && i < MAXSIZE)
	{
		switch(s[i])
		{
			case '(':
				opstk.top++;
				opstk.data[opstk.top] = '(';
				break;
			case ')':
				while(opstk.data[opstk.top]!='('){
					rpn->top++;
					rpn->data[rpn->top] = opstk.data[opstk.top]; 
					opstk.top--;
				}
				if(opstk.data[opstk.top] != '(')
				{
					printf("No open parenthesis! Wrong expression!");
					return NULL;
				}	
				opstk.top--;
				break;
			case '+':
			case '-':
				while (opstk.top != -1 && opstk.data[opstk.top] != '(')
                                {
                                        rpn->top++;
                                        rpn->data[rpn->top] = opstk.data[opstk.top];
                                        opstk.top--;
                                }
                                opstk.top++;                                    
                                opstk.data[opstk.top] = s[i]; 
                                break;
			case '*':
			case '/':
				while (opstk.top != -1 && opstk.data[opstk.top] != '(')              
                                {
                                        
					if(opstk.data[opstk.top] == '*' || opstk.data[opstk.top] == '/'){
					rpn->data[rpn->top] = opstk.data[opstk.top];
                                        opstk.top--;
                                        rpn->top++;
					}
					break;
                                } 
				opstk.top++;                                    
                                opstk.data[opstk.top] = s[i];
                                break;
			default:
				if(s[i] >= '0' && s[i] <= '9'){
					rpn->top++;
					rpn->data[rpn->top] = s[i];
				}
		}
		if(s[i] == '\n' || s[i] == '#')
			break;
		i++;
	}
// clear opstk
	while(opstk.top > -1){
		rpn->top++;
		rpn->data[rpn->top] = opstk.data[opstk.top];	
		opstk.top--;
	}
	return rpn;
}

int main()
{
	char s[14] = {'5','+','2','*','(','1','+','6',')','-','8','/','2','\0'};
	int i;
	SqStack *ss;
	ss = createRPN(s);
	for(i = 0; i <= ss->top; i++)
		printf("%c", ss->data[i]);
	printf("\n");
	exit(0);
}
