#ifndef _CARS
#define _CARS
struct PassengerVehicle
{
	char name[30];
	int capacity;
	float price_in_lakhs;
};

typedef struct PassengerVehicle Car;

void print_car_details(Car);

void sort(Car[], int);

#endif
