#include "Car.h"

#include<stdlib.h>

int number_of_cars = 3;

static Car* cars_in_showroom;

Car* create_showroom()
{
	cars_in_showroom = (Car*) malloc(sizeof(Car) * number_of_cars);
	return cars_in_showroom;
}

void destroy_showroom()
{
	free(cars_in_showroom);
}
