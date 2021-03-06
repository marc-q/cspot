/* Copyright 2016 - 2017 Marc Volker Dickmann
 * Project: CSpot
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../lib/dutils.h"
#include "../src/cspot_filter.h"

#define TESTS_AMOUNT 2
#define TESTS_FAIL 0
#define TESTS_PASS 1

/* |--------------------------------------------|
   |			Utils			|
   |--------------------------------------------| */

/*
 *	Function: tst_print_success (const char *tstname);
 *	Description: Prints the test success message.
 *	InitVersion: 0.0.1
 */
static void
tst_print_success (const char *tstname)
{
	printf ("%s:", tstname);
	
	if (strlen (tstname) < 15)
	{
		printf ("\t\t\t");
	}
	else if (strlen (tstname) < 23)
	{
		printf ("\t\t");
	}
	else
	{
		printf ("\t");
	}
	
	printf ("%sSUCCESS%s\n", BC_BLD_GREEN, BC_TXT_RST);
}

/*
 *	Function: tst_print_fail (const char *tstname);
 *	Description: Prints the test failure message.
 *	InitVersion: 0.0.1
 */
static void
tst_print_fail (const char *tstname)
{
	printf ("%s:", tstname);
	
	if (strlen (tstname) < 15)
	{
		printf ("\t\t\t");
	}
	else if (strlen (tstname) < 23)
	{
		printf ("\t\t");
	}
	else
	{
		printf ("\t");
	}
	
	printf ("%sFAIL%s\n", BC_BLD_RED, BC_TXT_RST);
}

/*
 *	Function: tst_print_summary (const int points);
 *	Description: Prints the summary of all tests.
 *	InitVersion: 0.0.1
 */
static void
tst_print_summary (const int points)
{
	printf ("\n+=======================+\n");
	printf ("|  Summary of all tests |\n");
	printf ("+=======================+\n");
	printf ("|  Tests: \t%i\t|\n", TESTS_AMOUNT);
	printf ("+-----------------------+\n");
	printf ("|  Passed:\t%i\t|\n", points);
	printf ("|  Failed:\t%i\t|\n", TESTS_AMOUNT-points);
	printf ("+-----------------------+\n");
}

/* |--------------------------------------------|
   |			Tests			|
   |--------------------------------------------| */

static int
tst_filter_is_empty (void)
{
	if (cspot_filter_is_empty ("\0") &&
	    cspot_filter_is_empty (" \0") &&
	    cspot_filter_is_empty ("\t\n\0") &&
	    !cspot_filter_is_empty ("a\0") &&
	    !cspot_filter_is_empty (".\n\0") &&
	    !cspot_filter_is_empty (" a simple test.\n\0"))
	{
		tst_print_success ("Filter_IsEmpty");
		return TESTS_PASS;
	}
	
	tst_print_fail ("Filter_IsEmpty");
	return TESTS_FAIL;
}

static int
tst_filter_ending_char (void)
{
	if (cspot_filter_ending_char ("aa \n\0", ' ') &&
	    cspot_filter_ending_char ("aa\t\n\0", '\t') &&
	    cspot_filter_ending_char ("}\t\n\0", '\t') &&
	    !cspot_filter_ending_char ("\n\0", '\t') &&
	    !cspot_filter_ending_char (".aaa\n\0", '\t') &&
	    !cspot_filter_ending_char ("\n\0", '\t'))
	{
		tst_print_success ("Filter_EndingChar");
		return TESTS_PASS;
	}
	
	tst_print_fail ("Filter_EndingChar");
	return TESTS_FAIL;
}

int
main (int argc, char *argv[])
{
	printf ("CSpot-Tests (C) 2016 - 2017 Marc Volker Dickmann\n\n");
	
	int points = 0;
	
	points += tst_filter_is_empty ();
	points += tst_filter_ending_char ();
	
	tst_print_summary (points);
	return 0;
}
