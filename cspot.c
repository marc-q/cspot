/* Copyright 2016 Marc Volker Dickmann */
/* Project: CSpot */
#include <stdio.h>
#include <string.h>

static void cspot_log_error (char *description)
{
	printf ("Error: %s\n", description);
}

static void cspot_log_highlight (char *description, unsigned int line, unsigned int column)
{
	printf ("Highlight: %s at L: %i C: %i.\n", description, line, column);
}

static void cspot_file_process (char *filename)
{
	unsigned int linecount;
	char line[250];
	FILE *src_file;
	
	src_file = fopen (filename, "r");
	
	if (src_file == NULL)
	{
		cspot_log_error ("Can't read the file!");
		return;
	}
	
	linecount = 1;
	
	while (fgets (line, sizeof (line), src_file) != NULL)
	{
		if (strlen (line) > 2)
		{
			/* INFO: strpbrk is used to only report lines with content.*/
			/* TODO: Find a better solution to this! */
			if (line[strlen (line)-2] == ' ' &&
			    strpbrk (line, "abcdefghijklmnopqrstufwxyz.,<{[]}>'#\\/\"!") != NULL)
			{
				cspot_log_highlight ("Found an ending space", linecount, strlen (line)-1);
			}
			else if (line[strlen (line)-2] == '\t' &&
				 strpbrk (line, "abcdefghijklmnopqrstufwxyz.,<{[]}>'#\\/\"!") != NULL)
			{
				cspot_log_highlight ("Found an ending tab", linecount, strlen (line)-1);
			}
		}
		
		linecount++;
	}
	
	fclose (src_file);
}

int main (int argc, char *argv[])
{
	printf ("CSpot v. 0.0.1 A (C) 2016 Marc Volker Dickmann\n\n");
	
	if (argc == 2)
	{
		cspot_file_process (argv[1]);
	}
	
	return 0;
}
