/* Copyright 2016 - 2017 Marc Volker Dickmann */
/* Project: CSpot */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "cspot_filter.h"

bool cspot_filter_is_empty (char *str)
{
	unsigned int i;
	
	for (i = 0; i < strlen (str); i++)
	{
		if (isspace (str[i]) == 0)
		{
			return false;
		}
	}
	
	return true;
}

bool cspot_filter_ending_char (char *str, char c)
{
	if (cspot_filter_is_empty (str) == false &&
	    str[strlen (str)-2] == c)
	{
		return true;
	}
	
	return false;
}
