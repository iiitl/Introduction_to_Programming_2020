#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 5	// CAPACITY is a constant (not a variable)

/*
 * To know what this code does, read this link:
 * https://queueoverflow.com/questions/17318886/fflush-is-not-working-in-linux
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
	int i, op_code, op, front = -1, rear = -1;
	char choice;

	do
	{
		system("clear"); // Invokes the clear command.
				 // "Should" work on most Linux environments !!
				 // Otherwise, just remove this

		printf("We have an queue with capacity %d\n", CAPACITY);
		printf("Press Ctrl+C anytime to exit\n");

		if(front == -1 && rear == -1)
			printf("The queue is currently empty\n");
		else
		{
			printf("The queue currently looks like this (from front to rear):\n");
			for(i = 0; i < front; i++)
				printf("X     ");
			for(i = front; i <= rear; i++)
				printf("%-6d", arr[i]);
			printf("\n");
		}
		printf("front = %d, rear = %d\n", front, rear);

		printf("What operation do you want to try out?\n");
		printf("Enter 1 for enqueue\n");
		printf("Enter 2 for dequeue\n");
		printf("Enter 3 left shift elements\n");
		scanf("%d", &op_code);

		switch(op_code)
		{
			case 1:
				printf("Enqueue Operation\n");
				
				// Check for vacancy
				if(rear == CAPACITY-1)
				{
					if(front == 0)
						printf("The queue is full; dequeue some elements first !\n");
					else
						printf("Shift the elements to the left first !\n");
					break;
				}

				printf("Enter the value to enqueue: ");
				scanf("%d", &op);

				// Enqueue the new element
				arr[++rear] = op;
				if(rear == 0)
					front = 0;

				break;
			case 2:
				printf("Dequeue Operation\n");

				// Check if queue has any elements
				if(front == -1 || front == rear+1)
				{
					printf("The queue is empty; add some elements first !\n");
					break;
				}


				// Update the rear and front variables
				printf("Dequeued %d from the queue\n", arr[front++]);

				break;
			case 3:
				printf("Shifting elements to the left to create space\n");
				
				if(front == rear+1)
				{
					printf("The queue is empty; I am just resetting the front and rear\n");
					front = rear = -1;
					break;
				}
				else if(front == 0)
				{
					printf("The elements are aleady to the left of queue\n");
					break;
				}

				// Shift elements to the left
				for(i = front; i < rear - 1; i++)
					arr[i] = arr[i+1];

				rear -= front;
				front = 0;

				break;
			default:
				printf("Doesn't look like a valid operation code !!\n");
		}

		printf("Do you want to continue? (y/n): ");
		clean_stdin();
		choice = getchar();
	}
	while(choice == 'y' || choice == 'Y');

	return 0;
}
