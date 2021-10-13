#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 5

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
	int i, op_code, op, top = -1;
	char choice;

	do
	{
		system("clear"); // Invokes the clear command.
				 // "Should" work on most Linux environments !!
				 // Otherwise, just remove this

		printf("We have a stack with capacity %d\n", CAPACITY);
		printf("Press Ctrl+C anytime to exit\n");

		if(top == -1)
			printf("The stack is currently empty\n");
		else
		{
			printf("The stack currently looks like this (top first):\n");
			for(i = top; i >= 0; i--)
				printf("%-6d", arr[i]);
			printf("\n");
		}

		printf("What operation do you want to try out?\n");
		printf("Enter 1 for push\n");
		printf("Enter 2 for pop\n");
		scanf("%d", &op_code);

		switch(op_code)
		{
			case 1:
				printf("Push Operation\n");
				
				// Check for vacancy
				if(top == CAPACITY-1)
				{
					printf("The stack is full; pop some elements first !\n");
					break;
				}

				printf("Enter the value to push: ");
				scanf("%d", &op);

				// Push the new element
				arr[++top] = op;

				break;
			case 2:
				printf("Pop Operation\n");

				// Check if stack has any elements
				if(top == -1)
				{
					printf("The stack is empty; push some elements first !\n");
					break;
				}

				printf("Popped %d from the stack\n", arr[top--]);

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
