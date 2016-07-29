/* Copyright 2016 Marc Volker Dickmann */
/* Project: CSpot */
#include <stdio.h>
#include "cspot_log.h"

void cspot_log_error (char *description)
{
	printf ("Error: %s\n", description);
}

void cspot_log_highlight (char *description, unsigned int line, unsigned int column)
{
	printf ("Highlight: %s at L: %i C: %i.\n", description, line, column);
}
