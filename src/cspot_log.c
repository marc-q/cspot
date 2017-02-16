/* Copyright 2016 - 2017 Marc Volker Dickmann
 * Project: CSpot
 */
#include <stdio.h>
#include "cspot_log.h"

void
cspot_log_error (const char *description)
{
	printf ("Error: %s\n", description);
}

void
cspot_log_highlight (const char *description, const size_t line, const size_t column)
{
	printf ("Highlight: %s at L: %zu C: %zu.\n", description, line, column);
}
