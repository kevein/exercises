#include <stdio.h>
#include <string.h>

int bitcount(unsigned x){
	int b;
	for(b = 0; x != 0; x >>= 1)
		if(x & 01)
			b++;
	return b;
}

int _bitcount(unsigned x){
	if (x == 0) return 0;
	int b = 1;
	while(x &= (x-1))
		b++;
	return b;
}

int main(int argc, char* argv[]){

	int test = atoi(argv[1]);
	int reval1, reval2;
	reval1 = bitcount(test);
	reval2 = _bitcount(test);
	printf ("rev1 is %d while rev2 is %d\n", reval1, reval2);
	return 0;

}
