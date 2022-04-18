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

// ================== Libraries ==================

// standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// user libraries 
#include "showMenu.h"
#include "file_reading.h"
#include "fourViews.h"


// ================== Utility Functions ==================

void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n')
	{
		; // do nothing!
	}
}

void suspend(void)
{
	putchar('\n');
	printf("< Press [ENTER] key to continue >");
	clearInputBuffer();
	putchar('\n');
}

int inputIntRange(int low, int high)
{

	int intValue;
	char newLine;

	scanf("%d%c", &intValue, &newLine);

	// repeat if not within range or not an integer
	do
	{
		if (newLine != '\n')
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
			scanf("%d%c", &intValue, &newLine);
		}
		else if (intValue < low || intValue > high)
		{
			printf("ERROR! Value must be between %d and %d inclusive: ", low, high);
			scanf("%d%c", &intValue, &newLine);
		}

	} while (intValue < low || intValue > high || newLine != '\n');

	return intValue;
}


// converts data that has cm into mm 
int conversionResult(struct WeatherRecord arr[], int howManyRecords)
{
	int result = 0;
	int i;

	for (i = 0; i < howManyRecords; i++)
	{
		if (arr[i].precipAmt != 0)
		{
			if (arr[i].unit == 'c')
			{
				arr[i].precipAmt = arr[i].precipAmt * 10;
			}
		}
	}
	return result;
}

// reverses any conversions that have been done previously
int reverseConversion(struct WeatherRecord arr[], int howManyRecords)
{
	int result = 0;
	int i;

	for (i = 0; i < howManyRecords; i++)
	{
		if (arr[i].precipAmt != 0)
		{
			if (arr[i].unit == 'c')
			{
				arr[i].precipAmt = arr[i].precipAmt / 10;
			}
		}
	}
	return result;
}

// ================== VIEW #1 - All Data ==================

void viewAllData(struct WeatherRecord arr[], int howManyRecords)
{
	int i = 0; // for the  inner for loop 
	int j; // for the outer for loop 
	int x = 1; // for the steps counter 
	int times = howManyRecords / STEPS; // for counting the batches of records

		// how many times to repeat this (inc. remainder)
		for (j = 0; j < times + 1; j++)
		{
				int steps = 15;
				// for loop to check through the weatherdata[array]
				for (i = (steps * x - steps); i < steps * x; i++)
				{
					if (arr[i].precipAmt != 0)// if the field is not empty 
					{
						displaySingleRecord(&arr[i]);
					}
				}
				x++;
				if (x < times + 2)
				{
					suspend(); // clearInputBuffer
				}
				else // for the last time data's displayed 
				{
					putchar('\n');
				}
		}
}

// ================== VIEW #2 - By Region ==================

// adding percipitation values to each region
void summaryRegion(struct WeatherRecord arr[], int howManyRecords,
	double* totalWestern,
	double* totalEastern,
	double* totalNorthern,
	double* totalCentral)
{
	int i;

	// loops through all of the records
	for (i = 0; i < howManyRecords; i++)
	{
		switch (arr[i].location.regionCode)
		{
		// if the region code is 10
		case 10:
			*totalWestern += arr[i].precipAmt;
			break;
		// if the region code is 20
		case 20:
			*totalNorthern += arr[i].precipAmt;
			break;
		// if the region code is 30
		case 30:
			*totalEastern += arr[i].precipAmt;
			break;
		// if the region code is 40
		case 40:
			*totalCentral += arr[i].precipAmt;
			break;
		}
	}
}

// sorting the regions by their percipitation (DESCENDING order)
void sortByRegion(struct Region r[], int length)
{
	int i, j;
	struct Region temp;

	// length-1 because the last element is already in place 
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{	
			// comparing two consecutive values in the array
			if (r[i].totalRegion < r[j].totalRegion)
			{
				// swapping values
				temp = r[i];
				r[i] = r[j];
				r[j] = temp;
			}
		}
	}

}

// viewing the regions
void viewByRegion(struct WeatherRecord arr[], int howManyRecords)
{
	int i; 

	// the total percipitation of all regions
	double totalWestern = 0;
	double totalEastern = 0;
	double totalNorthern = 0;
	double totalCentral = 0;

	// get the SUM of the percipitation for each region
	summaryRegion(arr, howManyRecords, &totalWestern, 
					                   &totalEastern, 
					                   &totalNorthern, 
					                   &totalCentral);

			// allocate memory for 4 new structs 
			struct Region region[4] =
			{
				{10, "Western", totalWestern},
				{20, "Northern", totalNorthern},
				{30, "Eastern", totalEastern},
				{40, "Central", totalCentral}
			};


			// display the SUM value by region codes
			sortByRegion(region, 4);

			// print all information about the regions
			for (i = 0; i < 4; i++)
			{
				printf("    %d %s\t%10.lf\n",
					region[i].regionDirection,
					region[i].regionName,
					region[i].totalRegion);
			}

			// print the total and the average  
			printf("------ -------- ----------\n");
			double total = totalWestern + 
						   totalEastern + 
						   totalNorthern + 
						   totalCentral;
			printf("         Total:      %.lf\n", total);
			double average = 0.25 * (total);
			printf("       Average:   %.2lf\n", average);

			putchar('\n');
}

// ================== VIEW #3 - By Month ==================

// adding percipitation values to each month
void summaryMonth(struct WeatherRecord arr[], int howManyRecords,
	int* totalJanuary,
	int* totalFebruary,
	int* totalMarch,
	int* totalApril,
	int* totalMay,
	int* totalJune,
	int* totalJuly,
	int* totalAugust,
	int* totalSeptember,
	int* totalOctober,
	int* totalNovember,
	int* totalDecember)
{
	int i;

	// looping through all of the records
	for (i = 0; i < howManyRecords; i++)
	{
		switch (arr[i].date.month)
		{
		case 01:
			*totalJanuary += arr[i].precipAmt;
			break;

		case 02:
			*totalFebruary += arr[i].precipAmt;
			break;

		case 03:
			*totalMarch += arr[i].precipAmt;
			break;

		case 04:
			*totalApril += arr[i].precipAmt;
			break;

		case 05:
			*totalMay += arr[i].precipAmt;
			break;

		case 06:
			*totalJune += arr[i].precipAmt;
			break;

		case 07:
			*totalJuly += arr[i].precipAmt;
			break;

		case 8:
			*totalAugust += arr[i].precipAmt;
			break;

		case 9:
			*totalSeptember += arr[i].precipAmt;
			break;

		case 10:
			*totalOctober += arr[i].precipAmt;
			break;

		case 11:
			*totalNovember += arr[i].precipAmt;
			break;

		case 12:
			*totalDecember += arr[i].precipAmt;
			break;
		}
	}
}

// sorting the months by their percipitation (ASCENDING order)
void sortByMonth(struct Month m[], int n)
{
	int i, j;
	struct Month temp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (m[i].totalMonth > m[j].totalMonth)
			{
				temp = m[i];
				m[i] = m[j];
				m[j] = temp;
			}
		}
	}
}

void viewByMonth(struct WeatherRecord arr[], int howManyRecords)
{

	// total percipitation for each month
	int totalJanuary = 0;
	int totalFebruary = 0;
	int totalMarch = 0;
	int totalApril = 0;
	int totalMay = 0;
	int totalJune = 0;
	int totalJuly = 0;
	int totalAugust = 0;
	int totalSeptember = 0;
	int totalOctober = 0;
	int totalNovember = 0;
	int totalDecember = 0;

	int i;

	// getting the total percipitation for all moths
	summaryMonth(arr, howManyRecords, &totalJanuary, 
									  &totalFebruary, 
									  &totalMarch, 
									  &totalApril, 
									  &totalMay, 
									  &totalJune, 
									  &totalJuly, 
									  &totalAugust, 
									  &totalSeptember, 
									  &totalOctober, 
									  &totalNovember, 
									  &totalDecember);

	// allocate memory for the new struct
	struct Month month[12] =
	{
		{"January", totalJanuary},
		{"February", totalFebruary},
		{"March", totalMarch},
		{"April", totalApril},
		{"May", totalMay},
		{"June", totalJune},
		{"July", totalJuly},
		{"August", totalAugust},
		{"September", totalSeptember},
		{"October", totalOctober},
		{"November", totalNovember},
		{"December", totalDecember}
	};

			// Display the SUM of all percipitations by month
			sortByMonth(month, 12);

			// printing all of the information about each month
			for (i = 0; i < 12; i++)
			{
				printf("%9s\t%3d\n", month[i].nameMonth, 
									month[i].totalMonth); 
			}
			// print the total and the average  
			printf("--------- ----------\n");
			int sum = totalJanuary + 
					  totalFebruary + 
					  totalMarch + 
					  totalApril + 
					  totalMay + 
					  totalJune + 
					  totalJuly + 
					  totalAugust + 
					  totalSeptember + 
					  totalOctober + 
					  totalNovember + 
					  totalDecember;
			printf("   Total:      %d\n", sum);
			printf(" Average:    %.2lf\n", sum / 12.0);
			putchar('\n');
	
}

// ================== VIEW #4 - By Location ==================

// adding percipitation values to each city
void locationSummary(struct WeatherRecord arr[], int howManyRecords, 
	double* totalChatham,
	double* totalHalton,
	double* totalRenfrew,
	double* totalKenora,
	double* totalSimcoe,
	double* totalEssex,
	double* totalOttawa,
	double* totalThunderBay)
{
	int i;

	// looping through all of the records
	for (i = 0; i < howManyRecords; i++)
	{
		// adding percipitation values of each location
		if (strcmp(arr[i].location.name, "Chatham-Kent") == 0) 
		{
			*totalChatham += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Halton") == 0)
		{
			*totalHalton += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Kenora") == 0)
		{
			*totalKenora += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Simcoe") == 0)
		{
			*totalSimcoe += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Essex") == 0)
		{
			*totalEssex += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Ottawa") == 0)
		{
			*totalOttawa += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Thunder Bay") == 0)
		{
			*totalThunderBay += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Renfrew") == 0)
		{
			*totalRenfrew += arr[i].precipAmt;
		}

	}
}

// sorting the locations by their percipitation (DESCENDING order)
void sortByLocationName(struct Area r[], int n)
{
	int i, j;
	struct Area temp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (r[i].totalPercip < r[j].totalPercip)
			{
				//SWAP!
				temp = r[i];
				r[i] = r[j];
				r[j] = temp;
			}
		}
	}
}

// viewing the ordered locations
void viewByLocation(struct WeatherRecord arr[], int howManyRecords)
{
	// storing the total percipitation for each city
	double totalChatham = 0;
	double totalHalton = 0;
	double totalRenfrew = 0;
	double totalKenora = 0;
	double totalSimcoe = 0;
	double totalEssex = 0;
	double totalOttawa = 0;
	double totalThunderBay = 0;

	int i;

			// total for each location
			locationSummary(arr, howManyRecords, 
				&totalChatham, 
				&totalHalton, 
				&totalRenfrew, 
				&totalKenora, 
				&totalSimcoe, 
				&totalEssex, 
				&totalOttawa, 
				&totalThunderBay);

			// allocate memory for 8 location percipitation structs
			struct Area name[8] =
			{
				{"Chatham-Kent", totalChatham},
				{"Halton", totalHalton},
				{"Renfrew", totalRenfrew},
				{"Kenora", totalKenora},
				{"Simcoe", totalSimcoe},
				{"Essex", totalEssex},
				{"Ottawa", totalOttawa},
				{"Thunder Bay", totalThunderBay}
			};

			//display the SUM value by region name
			sortByLocationName(name, 8);

			// print the locations and percipitation
			for (i = 0; i < 8; i++)
			{
				printf("%15s\t%10.0f\n", name[i].regionName, name[i].totalPercip);
			}
			// print summary
			printf("--------------- ----------\n");
			double locationSum = totalChatham + 
								 totalHalton + 
				                 totalRenfrew + 
				                 totalKenora + 
				                 totalSimcoe + 
				                 totalEssex + 
				                 totalOttawa + 
				                 totalThunderBay;
			printf("         Total:      %.0f\n", locationSum);
			printf("       Average:    %.2lf\n", locationSum / 8.0);


			putchar('\n');
}