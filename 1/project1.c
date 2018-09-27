#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define SEPARATORS " \t\n"

int main (int argc, char ** argv)
{
	char buf[MAX_BUFFER];
	char * args[MAX_ARGS];
	char ** arg;
	char * prompt = "==>";

	while (!feof(stdin))
	{
		fputs(prompt, stdout);
		if(fgets(buf, MAX_BUFFER, stdin))
		{
			arg = args;
			*arg++ = strtok(buf, SEPARATORS);
			while ((*arg++ = strok(NULL, SEPARATORS)));

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
					
						continue;
					}
				}
				if (!strcmp(args[0], "environ"))
				{

				}
				if (!strcmp(args[0], "ditto"))
				{

				}
				if (!strcmp(args[0], "help"))
				{

				}
				if (!strcmp(args[0], "mimic"))
				{

				}
				if (!strcmp(args[0], "erase"))
				{

				}
				if (!strcmp(args[0], "morph"))
				{

				}
				if (!strcmp(args[0], "chdir"))
				{

				}
				else
				{
					
				}
