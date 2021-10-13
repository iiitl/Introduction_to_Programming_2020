#include<stdio.h>

#define square(x) x*x

int main()
{
	int sq1, sq2;

	sq1 = square(5);

	sq2 = square(sq1);

	printf("The square of 5 is %d\n", sq1);
	printf("The square of %d is %d\n", sq1, sq2);
}
