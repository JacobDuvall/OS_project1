#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define SEPARATORS " \t\n"

// shell with custom commands
int main (int argc, char ** argv)
{
	setbuf(stdout, NULL); 
	char buf[MAX_BUFFER]; //buf char of size MAX_BUFFER
	char * args[MAX_ARGS];//args pointer of size MAX_ARGS
	char ** arg; //arg double char pointer
	char * prompt = "==>"; //string to prompt user for input
	extern char **environ; //environment pointer
	char stringCat[1000]; // stringCat string array of size 1000
	char directory[1000]; //direcotry string array of size 1000
	FILE *file; //file file pointer
	char characters; //char characters to collect chracters from file
	FILE *old; //first file
	FILE *new; //second file

	if (argc > 1) //if a batchfile is argument
	{
		file = freopen(argv[1], "r", stdin); //reads batchfile as stdin
	}

	while (!feof(stdin)) // while EOF isnt reached
	{
		fputs(prompt, stdout); //print the prompt
		if(fgets(buf, MAX_BUFFER, stdin)) //collect the stdin
		{
			arg = args; 
			*arg++ = strtok(buf, SEPARATORS); //separate the input
			while ((*arg++ = strtok(NULL, SEPARATORS))); //iterate through the args and parse

			if (args[0]) { //if a command is given

				if (!strcmp(args[0], "wipe")) //wipe command
				{
					system("clear"); //clear the screen
					continue;
				}
				
				if (!strcmp(args[0], "esc")) //esc command
				{
					exit(0); //exit successfully
				}
				if (!strcmp(args[0], "filez")) //filez command
				{
					if (args[1] == NULL) //no file passed
					{
						popen("ls -1", "r"); //print each file on a new line
						continue;
					}
					else
					{
						printf("%s", args[1]); //print the filename
						continue;
					}
				}
				if (!strcmp(args[0], "environ")) //environment command
				{
					char ** env = environ;
					while (*env) printf("%s\n", *env++); //print the environemtn

					continue;
				}
				if (!strcmp(args[0], "ditto")) //ditto command
				{
					if (args[1] != NULL)
					{
					
						int i = 1;
						do
						{
							strcat(directory, args[i]); //concatenate the ditto string
							strcat(directory, " ");
							i++;
						} while (args[i] != NULL); //while the ditto string exists
						fprintf(stdout, "%s\n", directory); //print the string to stdout
						directory[0] = 0; //clear the array
						continue;
					}
					else
					{
						fprintf(stderr, "%s\n", "no text for ditto");
					}
				}
				if (!strcmp(args[0], "help")) //help command
				{
					system("cat /projects/1/README"); //print the README for help
					continue;
				}
				if (!strcmp(args[0], "mimic")) //mimic command
				{
					old = fopen(args[1], "r"); //open the first file for reading
					if (old == NULL)
					{
						fprintf(stderr, "%s\n", "no file one");	
						continue;
					}
					
					new = fopen(args[2], "w"); //open the second file for writing
					if (new == NULL)
					{
						fprintf(stderr, "%s\n", "no file two");
						continue;
					}				

					while ((characters = getc(old)) != EOF) //copy bit by bit while the first file still has chracters
					{
						putc(characters, new); //copy the chracters of teh first to the second
					}
					fclose(old); //close the first file
					fclose(new);//close the second file
					continue;
				}
				if (!strcmp(args[0], "erase")) //erase command
				{
					remove(args[1]); //erase the file given
					continue;
				}
				if (!strcmp(args[0], "morph")) //morph command
				{
					if (args[1] == NULL)
					{
						fprintf(stderr, "%s\n", "no files");
						continue;
					}

					old = fopen(args[1], "r"); //open first file for reading
					new = fopen(args[2], "w"); //open second file for writing

					while ((characters = getc(old)) != EOF) //while characters exist in the first file
					{
						putc(characters, new); //copy the charcters of the first file to the second file
					}
					fclose(old); //close first file
					fclose(new); //close second file
					remove(args[1]); //remove first file
					continue;
				}
				if (!strcmp(args[0], "chdir")) //chdir command
				{
					if(args[1] == NULL)
					{
						getcwd(directory, sizeof(directory)); //get current directory
						fprintf(stdout, "%s\n", directory); //print the current directory
						directory[0] = 0; //clear the array
						continue;	
					}
					else 
					{
						chdir(args[1]); //change the directory to the one provided
						strcat(directory, "HOME="); //concatenate HOME= to new directory
						strcat(directory, args[1]);
						putenv(directory); //change the environment to new
						directory[0] = 0; //clear the array
						continue;
					}
				}
				else //pass all other commands to system
				{
					int i = 1;
					if (args[i] == NULL)
					{
						system(args[0]); //pass to system if only one arg
						continue;
					}
					else
					{
						strcat(directory, args[0]); //concatenate all arguments into one
						do
						{
							strcat(directory, " ");
							strcat(directory, args[i]);
							i++;
						} while (args[i] != NULL);
						
						system(directory); //pass the string of arguments into the system 
						directory[0] = 0; //clear array
						continue;
					}
				}
				arg = args; //otherwise print the arg to stdout
				while (*arg) fprintf(stdout, "%s ", *arg++);
				fputs("\n", stdout);
			}

		}
	}
	if (argc > 1)
	{
		fclose(file); // close the batchfile
	}
	return 0;
}

