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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//user libraries 
#include "showMenu.h"
#include "file_reading.h"
#include "fourViews.h"

//***********************************************************

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


void displayAllDataTableHeader(void)
{
	printf("Year Month Precip.Amt Unit Region Name\n"
		"---- ----- ---------- ---- ------ ---------------\n");
}


void displayByRegionTableHeader(void)
{
	printf("Region Name     Precip(mm)\n"
		"------ -------- ----------\n");
}

void displayByMonthTableHeader(void)
{
	printf("Month     Precip(mm)\n"
		"--------- ----------\n");
}

void displayByLocationTableHeader(void)
{
	printf("Location        Precip(mm)\n"
		"--------------- ----------\n");
}


void showMenu(struct WeatherRecord arr[], int howManyRecords)
{
	int selection = 1;
	int i = 0; //for the  inner for loop 
	int j; //for the outer for loop 
	int x = 1; //for the steps counter 
	int times = howManyRecords / STEPS; //for counting the batches of records to display

	double Wtotal = 0;
	double Etotal = 0;
	double Ntotal = 0;
	double Ctotal = 0;

	// for view by month
	int tJanuary = 0;
	int tFebruary = 0;
	int tMarch = 0;
	int tApril = 0;
	int tMay = 0;
	int tJune = 0;
	int tJule = 0;
	int tAugust = 0;
	int tSeptember = 0;
	int tOctober = 0;
	int tNovember = 0;
	int tDecember = 0;

	double chathamPercip = 0;
	double haltonPercip = 0;
	double renfrewPercip = 0;
	double kenoraPercip = 0;
	double simcoePercip = 0;
	double essexPercip = 0;
	double ottawaPercip = 0;
	double thunderBayPercip = 0;

	do {
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
		selection = inputIntRange(0, 4);
		putchar('\n');
		switch (selection)
		{
		case 0:
			putchar('\n');
			printf("Application Terminated!");
			putchar('\n');
			break;
		case 1:
			//view all data
			displayAllDataTableHeader();
			for (j = 0; j < times + 1; j++)//how many times to repeat this (inc. remainder)
			{
				int steps = 15;
				// for loop to check through the weatherdata[array]
				for (i = (steps * x - steps); i < steps * x; i++)
				{
					if (arr[i].precipAmt != 0)//if the field is not empty 
					{
						displaySingleRecord(&arr[i]);
					}
				}
				x++;
				if (x < times + 2)
				{
					suspend(); // clearInputBuffer
				}
				else //for the last time data's displayed 
				{
					putchar('\n');
				}
			}
			break;

			//***************************************************//
		case 2:
			//***view by region*** 
			displayByRegionTableHeader();

			//convert cm to mm
			conversionResult(arr, howManyRecords);

			//SUM the value of colum#5 (region code by percipiration amount)
			summaryRegion(arr, howManyRecords, &Wtotal, &Etotal, &Ntotal, &Ctotal);

			//***sort the values DESCENDING:

			// allocate memory for 4 new structs 
			struct Region region[4] =
			{
				{10, "Western", Wtotal},
				{20, "Northern", Ntotal},
				{30, "Eastern", Etotal},
				{40, "Central", Ctotal}
			};


			//display the SUM value by region codes
			sortByRegion(region, 4);

			for (i = 0; i < 4; i++)
			{
				printf("    %d %s\t%10.lf\n",
					region[i].regionDirection,
					region[i].regionName,
					region[i].totalRegion);
			}

			//print summary 
			printf("------ -------- ----------\n");
			double total = Wtotal + Etotal + Ntotal + Ctotal;
			printf("         Total:      %.lf\n", total);
			double average = 0.25 * (total);
			printf("       Average:   %.2lf\n", average);


			putchar('\n');
			break;

			//***************************************************//

		case 3://view by month 

			displayByMonthTableHeader();

			//convert cm to mm
			conversionResult(arr, howManyRecords);

			// Total for each month
			summaryMonth(arr, howManyRecords, &tJanuary, &tFebruary, &tMarch, &tApril, &tMay, &tJune, &tJule, &tAugust, &tSeptember, &tOctober, &tNovember, &tDecember);

			//allocate memory for the new struct
			struct Month month[12] =
			{
				{"January", tJanuary},
				{"February", tFebruary},
				{"March", tMarch},
				{"April", tApril},
				{"May", tMay},
				{"June", tJune},
				{"Jule", tJule},
				{"August", tAugust},
				{"September", tSeptember},
				{"October", tOctober},
				{"November", tNovember},
				{"December", tDecember}
			};

			//Display the SUM value by month
			sortByMonth(month, 12);

			for (i = 0; i < 12; i++)
			{
				printf("%9s\t%3d\n", month[i].nameMonth, month[i].totalMonth); // ??? FORMATTING
			}
			//print Summary
			printf("--------- ----------\n");
			int sum = tJanuary + tFebruary + tMarch + tApril + tMay + tJune + tJule + tAugust + tSeptember + tOctober + tNovember + tDecember;
			printf("   Total:      %d\n", sum);
			printf(" Average:    %.2lf\n", sum / 12.0);

			putchar('\n');
			break;

			//***************************************************//

		case 4:
			//view by location 
			displayByLocationTableHeader();

			//convert cm to mm
			conversionResult(arr, howManyRecords);

			// total for each location
			locationSummary(arr, howManyRecords, 
				&chathamPercip, 
				&haltonPercip, 
				&renfrewPercip, 
				&kenoraPercip, 
				&simcoePercip, 
				&essexPercip, 
				&ottawaPercip, 
				&thunderBayPercip);

			// allocate memory for 8 location percipitation structs
			struct Area name[8] =
			{
				{"Chatham-Kent", chathamPercip},
				{"Halton", haltonPercip},
				{"Renfrew", renfrewPercip},
				{"Kenora", kenoraPercip},
				{"Simcoe", simcoePercip},
				{"Essex", essexPercip},
				{"Ottawa", ottawaPercip},
				{"Thunder Bay", thunderBayPercip}
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
			double locationSum = chathamPercip + 
								 haltonPercip + 
				                 renfrewPercip + 
				                 kenoraPercip + 
				                 simcoePercip + 
				                 essexPercip + 
				                 ottawaPercip + 
				                 thunderBayPercip;
			printf("         Total:      %.0f\n", locationSum);
			printf("       Average:    %.2lf\n", locationSum / 8.0);


			putchar('\n');
			break;
		}

	} while (selection);
}
