#include<stdio.h>
#include<ctype.h>

#include "Car.h"

int compare(Car c1, Car c2)
{
	int i = -1;
	// We don't really need to convert the 
	// names to lowercase, but this is just
	// to show you the "pass by value" part.
	// The changes made to c1 and c2 here,
	// are not reflected back !!
	while(c1.name[++i] != '\0')
		c1.name[i] = tolower(c1.name[i]);
	i = -1;
	while(c2.name[++i] != '\0')
		c2.name[i] = tolower(c2.name[i]);
	i = 0;
	while(c1.name[i] != '\0' && c2.name[i] == '\0' 
			&& c1.name[i] == c2.name[i])
		i++;
	return c1.name[i] - c2.name[i];
}

void swap(Car* c1, Car* c2)
{
	Car c3 = *c1;
	*c1 = *c2;
	*c2 = c3;
}

void print_car_details(Car car)
{
	printf("-------------------------\n");
	printf("%s\n", car.name);
	printf("Capacity: %d people\n", car.capacity);
	printf("Price: %05.2f lakhs\n", car.price_in_lakhs);
	printf("-------------------------\n");
}

void sort(Car cars[], int len)
{
	int i, j;
	for(i = 0; i < len - 1; i++)
		for(j = 0; j < len - 1 - i; j++)
			if(compare(cars[j], cars[j+1]) > 0)
				swap(&cars[j], &cars[j+1]);
}
