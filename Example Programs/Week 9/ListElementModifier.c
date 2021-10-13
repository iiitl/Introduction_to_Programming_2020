#include<stdio.h>
#include<string.h>

/*
 * To know what this code does, read this link:
 * https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
 * We will discuss non-library functions in Week 7
 */
void clean_stdin(void)
{
	int c;
	do
	{
		c = getchar();
	}
	while (c != '\n' && c != EOF);
}

int main()
{
	int number_of_elements, i, temp, index;
	FILE* fptr = NULL;
	char choice, file_name[22];

	printf("Enter the name of the file containing the list (max 20 chars): ");	
	fgets(file_name, 20, stdin);

	file_name[strlen(file_name)-1] = '\0'; // To remove the extra \n character

	fptr = fopen(file_name, "rb+"); //"r" - read, "b" - binary, "+" - allow write

	// Read the number of elements in the list
	fread(&number_of_elements, sizeof(int), 1, fptr);

	if(number_of_elements > 0)
	{
		printf("Number of elements: %d\n", number_of_elements);
		printf("The current position in the file is byte#%ld\n", ftell(fptr));
		printf("Which element should I fetch (starting from 1)?\n");
		scanf("%d", &index);
		if(index > 0 && index < number_of_elements)
		{
			fseek(fptr, (index-1)*sizeof(int), SEEK_CUR);
			fread(&temp, sizeof(int), 1, fptr);
			printf("The element at that position is %d\n", temp);
			printf("Do you want to change it? Y/N: ");
			clean_stdin();
			choice = getchar();
			if(choice == 'y' || choice == 'Y')
			{
				printf("Enter the new integer: ");
				scanf("%d", &temp);
				fseek(fptr, -sizeof(int), SEEK_CUR);
				fwrite(&temp, sizeof(int), 1, fptr);
				printf("Done !!\n");
			}
		}
		else
			printf("Invalid index\n");
	}
	else
		printf("There are no elements in this list\n");

	fclose(fptr);
}
