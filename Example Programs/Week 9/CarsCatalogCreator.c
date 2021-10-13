#include<stdio.h>
#include<string.h>
#include "Car.h"

int main()
{
	Car cars[3];
	int i;
	FILE *fptr = fopen("catalog.bin", "wb");

	strcpy(cars[0].name, "Toyota Innova Crysta");
	cars[0].capacity = 8;
	cars[0].price_in_lakhs = 16.27;

	strcpy(cars[1].name, "Hyundai Creta");
	cars[1].capacity = 5;
	cars[1].price_in_lakhs = 10;

	strcpy(cars[2].name, "Kia Seltos");
	cars[2].capacity = 5;
	cars[2].price_in_lakhs = 9.9;

	printf("Creating the Cars Catalog\n");
	fwrite(cars, sizeof(Car), 3, fptr);
	printf("Done...\n");
}
