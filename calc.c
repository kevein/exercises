#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	double num1 = atof(argv[1]);
	double num2 = atof(argv[3]);
	char *operator = argv[2];
	double tmp = 0; 
	if (*operator == '+')
		tmp = num1 + num2;
	else if (*operator == '-')
		tmp = num1 - num2;
	else if (*operator == 'x' || *operator == '*')
		tmp = num1 * num2;
	else if (*operator == '/')
		tmp = num1 / num2;
	else
		return -1;
	printf("%.7f\n",tmp);

}
