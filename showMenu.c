/*
*****************************************************************************
						Final Exam - Question 1

Full Names  :
Anna Dmitrienko(ID 120412218), admitrienko@myseneca.ca
Artem Ruzaev (ID 124086216), aruzaev@myseneca.ca
Kseniia Katashova (ID 138164207), kkatashova@myseneca.ca

Section    : NPP

Authenticity Declaration:
We declare this submission is the result of our own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of our own creation.
*****************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS

// standard c libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//user libraries 
#include "showMenu.h"
#include "file_reading.h"
#include "fourViews.h"

//***********************************************************

// displaying a record once
void displaySingleRecord(const struct WeatherRecord* arr)
{
	printf("%d %5.2d %10.1lf %4c %6d %s\n",
		arr->date.year,
		arr->date.month,
		arr->precipAmt,
		arr->unit,
		arr->location.regionCode,
		arr->location.name);

}

// table header for displaying everything
void displayAllDataTableHeader(void)
{
	printf("Year Month Precip.Amt Unit Region Name\n"
		"---- ----- ---------- ---- ------ ---------------\n");
}

// table header for displaying by region
void displayByRegionTableHeader(void)
{
	printf("Region Name     Precip(mm)\n"
		"------ -------- ----------\n");
}

// table header for displaying by month
void displayByMonthTableHeader(void)
{
	printf("Month     Precip(mm)\n"
		"--------- ----------\n");
}

// table header for displaying by the location
void displayByLocationTableHeader(void)
{
	printf("Location        Precip(mm)\n"
		"--------------- ----------\n");
}

void showMenu(struct WeatherRecord arr[], int howManyRecords)
{
	int selection = 0; // the selection of the user

	do {
		// main menu
		printf("=======================================================\n"
			"         Ontario Weather Analysis Service                     \n"
			"                  Year: 2021                                  \n"
			"=======================================================\n"
			"1. View all data\n"
			"2. View by region (sorted DESCENDING by precip.)\n"
			"3. View by month (sorted ASCENDING by precip.)\n"
			"4. View by location name (sorted DESCENDING by precip.)\n"
			"-------------------------------------------------------\n"
			"0. Exit\n"
			"-------------------------------------------------------\n"
			"Selection: ");
		// getting the selection
		selection = inputIntRange(0, 4);
		putchar('\n');
		switch (selection)
		{

		// ================== EXIT ==================

		case 0:
			printf("Application Terminated!");
			putchar('\n');
			break;

		// ================== Option #1 - All Data ==================

		case 1:
			displayAllDataTableHeader();
			viewAllData(arr, howManyRecords);
			break;

		// ================== Option #2 - By Region ==================

		case 2:
			conversionResult(arr, howManyRecords);
			displayByRegionTableHeader();
			viewByRegion(arr, howManyRecords);
			reverseConversion(arr, howManyRecords);
			break;

		// ================== Option #3 - By Month  ==================

		case 3:
			conversionResult(arr, howManyRecords);
			displayByMonthTableHeader();
			viewByMonth(arr, howManyRecords);
			reverseConversion(arr, howManyRecords);
			break;

		// ================== Option #4 - By Location  ==================

		case 4:
			conversionResult(arr, howManyRecords);
			displayByLocationTableHeader();
			viewByLocation(arr, howManyRecords);
			reverseConversion(arr, howManyRecords);
			break;
		}
		// execute while the selection isn't 0
	} while (selection);
}
