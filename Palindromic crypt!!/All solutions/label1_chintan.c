#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void) {
	int a, b;   //variables for storing numbers
	scanf("%d %d", &a, &b);
	
	if((a < 1 || a > 10000000) || (b < 1 || b > 10000000) )
	{
	    exit(1);
	}
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
