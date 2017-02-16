/* Copyright 2016 - 2017 Marc Volker Dickmann
 * Project: CSpot
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "cspot_filter.h"

bool
cspot_filter_is_empty (const char *str)
{
	const size_t len = strlen (str);
	
	for (size_t i = 0; i < len; i++)
	{
		if (isspace (str[i]) == 0)
		{
			return false;
		}
	}
	return true;
}

bool
cspot_filter_ending_char (const char *str, const char c)
{
	if (!cspot_filter_is_empty (str) &&
	    str[strlen (str) - 2] == c)
	{
		return true;
	}
	return false;
}
