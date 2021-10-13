#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "Car.h"
#include "input.h"
#include "Showroom.h"

int main()
{
	extern int number_of_cars;

	int i, temp;
	Car* cars_in_showroom = create_showroom();
	printf("Let us add %d cars to your showroom\n", number_of_cars);
	for(i = 0; i < number_of_cars; i++)
	{
		printf("\nDetails for Car#%d\n", (i+1));
		printf("Name: ");
		fgets(cars_in_showroom[i].name, 28, stdin);
		temp = strlen(cars_in_showroom[i].name);
		cars_in_showroom[i].name[temp-1] = '\0';
		printf("Capacity: ");
		scanf("%d", &cars_in_showroom[i].capacity);
		clean_stdin();
		printf("Price (in lakhs): ");
		scanf("%f", &cars_in_showroom[i].price_in_lakhs);
		clean_stdin();
	}

	printf("\nSorting the cars alphabetically be their names...\n");
	sort(cars_in_showroom, number_of_cars);

	printf("\nShowing the cars in the showroom\n");
	for(i = 0; i < number_of_cars; i++)
		print_car_details(cars_in_showroom[i]);
	destroy_showroom();
}
