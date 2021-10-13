#include<stdio.h>
#include "Car.h"

int main()
{
	Car car;
	int i;
	FILE *fptr = fopen("catalog.bin", "rb");

	printf("Reading the Cars Catalog\n");

	for(i = 0; i < 3; i++)
	{
		fread(&car, sizeof(Car), 1, fptr);
		printf("-------------------------\n");
		printf("%s\n", car.name);
		printf("Capacity: %d people\n", car.capacity);
		printf("Price: %05.2f lakhs\n", car.price_in_lakhs);
		printf("-------------------------\n");
	}
}
