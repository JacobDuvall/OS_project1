#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define SEPARATORS " \t\n"

int main (int argc, char ** argv)
{
	setbuf(stdout, NULL);
	char buf[MAX_BUFFER];
	char * args[MAX_ARGS];
	char ** arg;
	char * prompt = "==>";
	extern char **environ;
	char stringCat[1000];
	char directory[1000];
	FILE *file;
	char characters;
	FILE *old;
	FILE *new;

	if (argc > 1)
	{
		file = freopen(argv[1], "r", stdin);
	}

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
					popen("clear", "r");
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
						popen("ls -1", "r");
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
					if (args[1] != NULL)
					{
					
						int i = 1;
						do
						{
							strcat(directory, args[i]);
							strcat(directory, " ");
							i++;
						} while (args[i] != NULL);
						fprintf(stdout, "%s\n", directory);
						directory[0] = 0;
						continue;
					}
					else
					{
						fprintf(stderr, "%s\n", "no text for ditto");
					}
				}
				if (!strcmp(args[0], "help"))
				{
					system("cat /projects/1/README");
					continue;
				}
				if (!strcmp(args[0], "mimic"))
				{
					old = fopen(args[1], "r");
					if (old == NULL)
					{
						fprintf(stderr, "%s\n", "no file one");	
						continue;
					}
					
					new = fopen(args[2], "w");
					if (new == NULL)
					{
						fprintf(stderr, "%s\n", "no file two");
						continue;
					}				

					while ((characters = getc(old)) != EOF)
					{
						putc(characters, new);
					}
					fclose(old);
					fclose(new);
					continue;
				}
				if (!strcmp(args[0], "erase"))
				{
					remove(args[1]);
					continue;
				}
				if (!strcmp(args[0], "morph"))
				{
					if (args[1] == NULL)
					{
						fprintf(stderr, "%s\n", "no files");
						continue;
					}

					old = fopen(args[1], "r");
					new = fopen(args[2], "w");

					while ((characters = getc(old)) != EOF)
					{
						putc(characters, new);
					}
					fclose(old);
					fclose(new);
					remove(args[1]);
					continue;
				}
				if (!strcmp(args[0], "chdir"))
				{
					if(args[1] == NULL)
					{
						getcwd(directory, sizeof(directory));
						fprintf(stdout, "%s\n", directory);
						directory[0] = 0;
						continue;	
					}
					else 
					{
						chdir(args[1]);
						strcat(directory, "HOME=");
						strcat(directory, args[1]);
						putenv(directory);
						directory[0] = 0;
						continue;
					}
				}
				else
				{
					int i = 1;
					if (args[i] == NULL)
					{
						system(args[0]);
						continue;
					}
					else
					{
						strcat(directory, args[0]);
						do
						{
							strcat(directory, " ");
							strcat(directory, args[i]);
							i++;
						} while (args[i] != NULL);
						
						system(directory);
						directory[0] = 0;
						continue;
					}
				}
				arg = args;
				while (*arg) fprintf(stdout, "%s ", *arg++);
				fputs("\n", stdout);
			}

		}
	}
	if (argc > 1)
	{
		fclose(file);
	}
	return 0;
}

