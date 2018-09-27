#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define SEPARATORS " \t\n"

int main (int argc, char ** argv)
{
	char buf[MAX_BUFFER];
	char * args[MAX_ARGS];
	char ** arg;
	char * prompt = "==>";
	extern char **environ;
	char stringCat[1000];
	char directory[1000];

	while (!feof(stdin))
	{
		fputs(prompt, stdout);
		if(fgets(buf, MAX_BUFFER, stdin))
		{
			arg = args;
			*arg++ = strtok(buf, SEPARATORS);
			while ((*arg++ = strtok(NULL, SEPARATORS)));

			if (args[0]) {

				if (!strcmp(args[0], "wipe"))
				{
					system("clear");
					continue;
				}
				
				if (!strcmp(args[0], "esc"))
				{
					exit(0);
				}
				if (!strcmp(args[0], "filez"))
				{
					if (args[1] == NULL)
					{
						system("ls -1");
						continue;
					}
					else
					{
						printf("%s", args[1]);
						continue;
					}
				}
				if (!strcmp(args[0], "environ"))
				{
					char ** env = environ;
					while (*env) printf("%s\n", *env++);

					continue;
				}
				if (!strcmp(args[0], "ditto"))
				{
					
				}
				if (!strcmp(args[0], "help"))
				{
					system("cat README");
				}
				if (!strcmp(args[0], "mimic"))
				{

				}
				if (!strcmp(args[0], "erase"))
				{
					remove(args[1]);
					continue;
				}
				if (!strcmp(args[0], "morph"))
				{

				}
				if (!strcmp(args[0], "chdir"))
				{
					if(args[1] == NULL)
					{
						getcwd(directory, sizeof(directory));
						printf("%s\n", directory);
						directory[0] = 0;	
					}
					else 
					{
						strcat(directory, "cd ");
						strcat(directory, args[1]);
						printf("%s\n", args[1]);
						printf("%s\n", directory);
						system(directory);
					}
					continue;
				}
				else
				{
					
			
				}
				arg = args;
				while (*arg) fprintf(stdout, "%s ", *arg++);
				fputs("\n", stdout);
			}

		}
	}
	return 0;
}

