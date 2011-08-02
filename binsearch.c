#include <stdio.h>
#include <string.h>

int binsearch(int x, int v[], int n){
	int low, mid, high;
	low=0;
	high=n-1;
	
	while(low <= high){
		mid = (low+high)/2;
		if(v[mid] < x)
			low = mid-1; 
		else if(v[mid] > x)
			high = mid+1;
		else 
			return mid;
	}		
	return -1;
}

int main(int argc, char* argv[]){
	int a[50],i;
	for (i=0;i<50;i++)
		a[i] = i;
	int temp;
	int tosearch = atoi(argv[1]);
	printf("argv[1]: %d\n", tosearch);
	temp = binsearch(tosearch,a,50);
	printf("%d\n",temp);
	return 0;
}
