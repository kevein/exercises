#include <stdio.h>
#include <stdlib.h>

void insert(int R[], int n)
{
	int i,j,low,high,mid,tmp;
	for(i = 1; i < n; i++)
	{
		tmp = R[i];
		low = 0; high = i - 1;
		while(low <= high)
		{
			mid = (low+high)/2;
			if(tmp < R[mid])
				high = mid - 1;
			else 
				low = mid + 1;
		}
		for (j = i -1; j >= high +1; j--)
			R[j+1] = R[j];
		R[high+1] = tmp;
	}
}

int main()
{
	int i;
	int array[10] = {3,9,8,7,4,6,5,2,1,12};
	insert(array, 10);
	for(i=0 ; i<10; i++)
		printf("%d, ", array[i]);
	printf("\n");
	exit(0);
}
