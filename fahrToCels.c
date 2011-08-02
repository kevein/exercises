#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]){

	double fahr,cels;
	fahr = atof(argv[1]);
	cels = (5.0/9.0)*(fahr-32);
	
	printf("Celsius degree is: %f\n", cels);

}
