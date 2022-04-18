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


//utility functions 

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


	//repeat if not within range or not an integer
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





//this is to convert cm to mm 

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



//***VIEW#2


//this is to sum by region 
void summaryRegion(struct WeatherRecord arr[], int howManyRecords,
	double* WesternTotal,
	double* EasternTotal,
	double* NorthenTotal,
	double* CentralTotal)
{
	int i;

	for (i = 0; i < howManyRecords; i++)
	{
		switch (arr[i].location.regionCode)
		{
		case 10:
			*WesternTotal += arr[i].precipAmt;
			break;

		case 20:
			*NorthenTotal += arr[i].precipAmt;
			break;

		case 30:
			*EasternTotal += arr[i].precipAmt;
			break;

		case 40:
			*CentralTotal += arr[i].precipAmt;
			break;

		}

	}

}


void sortByRegion(struct Region r[], int length)
{
	int i, j;
	struct Region temp;

	//length-1 because the last element is already in place 
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (r[i].totalRegion < r[j].totalRegion)
			{
				//SWAP!
				temp = r[i];
				r[i] = r[j];
				r[j] = temp;
			}
		}
	}

}

//***VIEW#3
void summaryMonth(struct WeatherRecord arr[], int howManyRecords,
	int* TotalJanuary,
	int* TotalFebruary,
	int* TotalMarch,
	int* TotalApril,
	int* TotalMay,
	int* TotalJune,
	int* TotalJuly,
	int* TotalAugust,
	int* TotalSeptember,
	int* TotalOctober,
	int* TotalNovember,
	int* TotalDecember)
{
	int k;

	for (k = 0; k < howManyRecords; k++)
	{
		switch (arr[k].date.month)
		{
		case 01:
			*TotalJanuary += arr[k].precipAmt;
			break;

		case 02:
			*TotalFebruary += arr[k].precipAmt;
			break;

		case 03:
			*TotalMarch += arr[k].precipAmt;
			break;

		case 04:
			*TotalApril += arr[k].precipAmt;
			break;

		case 05:
			*TotalMay += arr[k].precipAmt;
			break;

		case 06:
			*TotalJune += arr[k].precipAmt;
			break;

		case 07:
			*TotalJuly += arr[k].precipAmt;
			break;

		case 8:
			*TotalAugust += arr[k].precipAmt;
			break;

		case 9:
			*TotalSeptember += arr[k].precipAmt;
			break;

		case 10:
			*TotalOctober += arr[k].precipAmt;
			break;

		case 11:
			*TotalNovember += arr[k].precipAmt;
			break;

		case 12:
			*TotalDecember += arr[k].precipAmt;
			break;
		}
	}
}

//sort by month ( by ascending by precipAmt)
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


void locationSummary(struct WeatherRecord arr[], int howManyRecords, 
	double* chathamPercip,
	double* haltonPercip,
	double* renfrewPercip,
	double* kenoraPercip,
	double* simcoePercip,
	double* essexPercip,
	double* ottawaPercip,
	double* thunderBayPercip)
{
	int i;

	for (i = 0; i < howManyRecords; i++)
	{
		if (strcmp(arr[i].location.name, "Chatham-Kent") == 0) 
		{
			*chathamPercip += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Halton") == 0)
		{
			*haltonPercip += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Kenora") == 0)
		{
			*kenoraPercip += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Simcoe") == 0)
		{
			*simcoePercip += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Essex") == 0)
		{
			*essexPercip += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Ottawa") == 0)
		{
			*ottawaPercip += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Thunder Bay") == 0)
		{
			*thunderBayPercip += arr[i].precipAmt;
		}
		else if (strcmp(arr[i].location.name, "Renfrew") == 0)
		{
			*renfrewPercip += arr[i].precipAmt;
		}

	}
}

void sortByLocationName(struct Region r[], int n)
{
	int i, j;
	struct Region temp;

	//length-1 because the last element is already in place 
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (r[i].totalRegion < r[j].totalRegion)
			{
				//SWAP!
				temp = r[i];
				r[i] = r[j];
				r[j] = temp;
			}
		}
	}
}