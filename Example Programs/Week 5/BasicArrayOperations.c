#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 5	// CAPACITY is a constant (not a variable)

/*
 * To know what this code does, read this link:
 * https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
 * We will discuss non-library functions in Week 7
 */
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main()
{
	int arr[CAPACITY];	// This is legal, for all C compilers
	int size = 0, i, op_code, op1, op2;
	char choice;

	do
	{
		system("clear"); // Invokes the clear command.
				 // "Should" work on most Linux environments !!
				 // Otherwise, just remove this

		printf("We have an array with capacity %d\n", CAPACITY);
		printf("Press Ctrl+C anytime to exit\n");

		if(size == 0)
			printf("The array is currently empty\n");
		else
		{
			printf("The array currently looks like this:\n");
			for(i = 0; i < size; i++)
				printf("%-6d", arr[i]);
			printf("\n");
		}

		printf("What operation do you want to try out?\n");
		printf("Enter 1 for insertion\n");
		printf("Enter 2 for deletion\n");
		scanf("%d", &op_code);

		switch(op_code)
		{
			case 1:
				printf("Insertion Operation\n");
				
				// Check for vacancy
				if(size == CAPACITY)
				{
					printf("The array is full; remove some elements first !\n");
					break;
				}

				printf("Enter the index where you would like to insert the value: ");
				scanf("%d", &op1);
				
				// Check if the index is valid
				if(op1 < 0 || op1 >= CAPACITY)
				{
					printf("Invalid insertion index\n");
					break;
				}
				else if(op1 > size)
				{
					printf("WARNING: The element will be added at the end, i.e. index %d\n",size);
					op1 = size;
				}
				
				printf("Enter the value to insert: ");
				scanf("%d", &op2);

				// Shift elements to the right
				for(i = size; i > op1; i--)
					arr[i] = arr[i-1];

				// Insert the new element
				arr[op1] = op2;

				// Update the size
				size++;
				
				break;
			case 2:
				printf("Deletion Operation\n");

				// Check if array has any elements
				if(size == 0)
				{
					printf("The array is empty; add some elements first !\n");
					break;
				}

				printf("Enter the index of the value you wish to delete: ");
				scanf("%d", &op1);


				// Check if the index is valid
				if(op1 < 0 || op1 >= CAPACITY)
				{
					printf("Invalid insertion index\n");
					break;
				}
				else if(op1 >= size)
				{
					printf("WARNING: The last element will be deleted, i.e. at index %d\n",size-1);
					op1 = size-1;
				}

				// Shift elements to the left
				for(i = op1; i < size - 1; i++)
					arr[i] = arr[i+1];

				// Update the size
				size--;

				break;
			default:
				printf("Doesn't look like a valid operation code !!\n");
		}

		printf("Do you want to continue? (y/N): ");
		clean_stdin();
		choice = getchar();
	}
	while(choice == 'y' || choice == 'Y');

	return 0;
}
