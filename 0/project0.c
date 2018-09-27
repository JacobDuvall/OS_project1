/*
 * Author: Jacob Duvall
 *
 * Created: 09.11.18
 *
 * Works with command line to accomplish the task of counting and displaying the 
 * ASCII occurences for a given file or manually passed type. If no arguments are 
 * passed along with the file, then the default is to display from ASCII decimal 32 
 * to ASCII decimal 125. If one arugment is passed, then the ASCII of the arugment
 * up until ASCII decimal 125 is shown. If two arugments are passed, then the ASCII 
 * value of the first argument up to the second argument is shown.
 *
 * @param {int} argc The number of arguments passed 
 * @param {char**} argv Double pointer to the text of the arguments passed 
 * @returns {0} Returns 0 to signify completion of the program
 */

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
			
			printf("Range:  -}\n"); //prints range 
			while (1) // loop forever until break is reached
			{
				characters = fgetc(inputFile); // fgetc is used to get the next character in the inputFile and assign its ascii value to characters
			
				if (characters == EOF) // loop until end of file is reached
				{
					break; // break from loop
				}
				asciiCountArray[characters] += 1; // increment the count by 1 for the given character within the array
			}
			for (asciiLooper = 32; asciiLooper < 126; asciiLooper++) // loop through the range for 0 arguments
			{
				printf("%c: ", asciiLooper); // print the ascii value
			       	
				if (asciiCountArray[asciiLooper] >= 1000) // if greater than 999 no spaces 
				{
				       printf("%d ", asciiCountArray[asciiLooper]); // print occurences
				}
		 		else if (asciiCountArray[asciiLooper] >= 100) // if greater than 99 one space
				{
					printf(" %d ", asciiCountArray[asciiLooper]); // print occureneces
				}		
				else if (asciiCountArray[asciiLooper] >= 10) // if greater than 9 two spaces
				{
					printf("  %d ", asciiCountArray[asciiLooper]); // print occurences
				}
				else // if less than 10 three spaces
				{
					printf("   %d ", asciiCountArray[asciiLooper]); // print occurences
				}

				for (xLooper = 0; xLooper < asciiCountArray[asciiLooper]; xLooper++) // loop through for the number of times # needs to be printed
				{
					printf("#"); // print #
				}
				printf("\n"); // print new line
			}
			fclose(inputFile); // close the open file

			break; // break from switch

		case 2: // 1 ASCII value to search for
			
			printf("Range: %s-}\n", argv[1]); // prints range 
			while (1) // loop forever until break is reached
			{
				characters = fgetc(inputFile); // fgetc is used to get the next character in the inputFile and assign its ascii value to characters

				if (characters == EOF) // loop until end of file is reached
				{
					break; // break from loop
				}
				asciiCountArray[characters] += 1; // increment the count by 1 for the given character within the array
			}
			for (asciiLooper = argv[1][0]; asciiLooper < 126; asciiLooper++) // loop through the range for 1 argument 
			{
				printf("%c: ", asciiLooper); // print the ascii value
				
				if (asciiCountArray[asciiLooper] >= 1000) // if greater than 1000 no spaces
				{
					printf("%d ", asciiCountArray[asciiLooper]); // print occurences 
				}
				else if (asciiCountArray[asciiLooper] >= 100) // if greater than 100 one space
				{
					printf(" %d ", asciiCountArray[asciiLooper]); // print occurences
				}
				else if (asciiCountArray[asciiLooper] >= 10) // if greater than 10 two spaces
				{
					printf("  %d ", asciiCountArray[asciiLooper]); // print occurences
				}
				else // if less than 10 three spaces
				{
					printf("   %d ", asciiCountArray[asciiLooper]); // print occurences
				}
				
				for (xLooper = 0; xLooper < asciiCountArray[asciiLooper]; xLooper++) // loop through for the number of times # needs to be printed
				{
					printf("#"); // print #
				}
				printf("\n"); // print new line
			}
			fclose(inputFile); // close the open file

			break; // break from switch

		case 3: // 2 ASCII values to search for
			
			printf("Range: %s-%s\n", argv[1], argv[2]); // prints range
			while (1) // loop forever until break is reached
			{
				characters = fgetc(inputFile); // fgetc is used to get the next character in the inputFile and assign its ascii value to characters

				if (characters == EOF) //loop until end of file is reached
				{
					break; // break from loop
				}
				asciiCountArray[characters] += 1; // increment the count by 1 for the given character within the array
			}
			for (asciiLooper = argv[1][0]; asciiLooper <= argv[2][0]; asciiLooper++) // loop through the range for 2 arguments
			{
				printf("%c: ", asciiLooper); // print the ascii value 
				
				if (asciiCountArray[asciiLooper] >= 1000) // if greater than 999 no spaces
				{
					printf("%d ", asciiCountArray[asciiLooper]); // print occurences
				}
				else if (asciiCountArray[asciiLooper] >= 100) // if greater than 99 one space
				{
					printf(" %d ", asciiCountArray[asciiLooper]); // print occurences
				}
				else if (asciiCountArray[asciiLooper] >= 10) // if greater than 9 two spaces
				{
					printf ("  %d ", asciiCountArray[asciiLooper]); // print occurences
				}
				else // if less than 10 three spaces
				{
					printf( "   %d ", asciiCountArray[asciiLooper]); // print occurences
				}

				for (xLooper = 0; xLooper < asciiCountArray[asciiLooper]; xLooper++) // loop through for the number of times # needs to be printed
				{
					printf("#"); // print #
				}
				printf("\n"); // print the new line
			}
			fclose(inputFile); // close the open file

			break; // break from switch

	}
	return 0; // return 0
}
