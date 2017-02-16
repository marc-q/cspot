/* Copyright 2016 - 2017 Marc Volker Dickmann
 * Project: CSpot
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "src/cspot_log.h"
#include "src/cspot_filter.h"

static void
cspot_file_process (const char *filename)
{
	FILE *src_file = fopen (filename, "r");
	
	if (src_file == NULL)
	{
		cspot_log_error ("Can't read the file!");
		return;
	}
	
	char line[250];
	size_t linecount = 1;
	
	while (fgets (line, sizeof (line), src_file) != NULL)
	{
		/* TODO: Find a better solution to this! */
		if (strlen (line) > 2)
		{
			if (cspot_filter_ending_char (line, ' '))
			{
				cspot_log_highlight ("Found an ending space", linecount, strlen (line) - 1);
			}
			else if (cspot_filter_ending_char (line, '\t'))
			{
				cspot_log_highlight ("Found an ending tab", linecount, strlen (line) - 1);
			}
		}
		
		linecount++;
	}
	
	fclose (src_file);
}

int
main (int argc, char *argv[])
{
	printf ("CSpot v. 0.0.1 A (C) 2016 - 2017 Marc Volker Dickmann\n\n");
	
	if (argc == 2)
	{
		cspot_file_process (argv[1]);
	}
	
	return 0;
}
