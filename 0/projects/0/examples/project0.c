#include <stdio.h>

int main(int argc, char** argv) 
{
	int numberOfArguments = argc; // number of arguments passed from command line
	FILE *inputFile = stdin; // the input given from the command line
	int asciiCountArray[255] = {0}; // array that will hold the number of # to be printed
	int characters; // characters from the input file are individually stored here
	int asciiLooper; // used to loop through the ascii array 
	int numberOfXs; // the number of #'s to print
	int xLooper; // loops through the numberOfXs

	switch(numberOfArguments) // either 1 2 or 3 arguments expected
	{
		case 1: // 0 ASCII values to search for
			
			printf("Range:  -}\n");
			while (1) 
			{
				characters = fgetc(inputFile);

				if(characters == EOF)
				{
					break;
				}
				asciiCountArray[characters] += 1;
			}
			for (asciiLooper = 32; asciiLooper < 126; asciiLooper++) 
			{
				printf("%c:    %d ", asciiLooper, asciiCountArray[asciiLooper]);
				for (xLooper = 0; xLooper < asciiCountArray[asciiLooper]; xLooper++) 
				{
					printf("#");
				}
				printf("\n");
			}
			fclose(inputFile);

			break;

		case 2: // 1 ASCII value to search for
			
			printf("Range: %s-}\n", argv[1]);
			while (1) 
			{
				characters = fgetc(inputFile);
				if (characters == EOF) 
				{
					break;
				}
				asciiCountArray[characters] += 1;
			}
			for (asciiLooper = argv[1][0]; asciiLooper < 126; asciiLooper++)
			{
				printf("%c:    %d ", asciiLooper, asciiCountArray[asciiLooper]);
				for (xLooper = 0; xLooper < asciiCountArray[asciiLooper]; xLooper++) 
				{
					printf("#");
				}
				printf("\n");
			}
			fclose(inputFile);

			break;

		case 3: // 2 ASCII values to search for
			
			printf("Range: %s-%s\n", argv[1], argv[2]);
			while (1) 
			{
				characters = fgetc(inputFile);
				if (characters == EOF)
				{
					break;
				}
				asciiCountArray[characters] += 1;
			}
			for (asciiLooper = argv[1][0]; asciiLooper <= argv[2][0]; asciiLooper++)
			{
				printf("%c:    %d ", asciiLooper, asciiCountArray[asciiLooper]);
				for (xLooper = 0; xLooper < asciiCountArray[asciiLooper]; xLooper++)
				{
					printf("#");
				}
				printf("\n");
			}
			fclose(inputFile);

			break;

	}
	return 0;
}
