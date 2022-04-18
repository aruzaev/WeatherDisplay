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
#include "file_reading.h"
#include "showMenu.h"
#include "fourViews.h"


#define RECORDS_MAX 250
struct WeatherRecord arr[RECORDS_MAX];

int main()
{
	int howManyRecords;
	FILE* textFile;
	textFile = fopen("weatherdata.txt", "r");
	if (textFile == NULL)
	{
		printf("OPEN ERROR!\n");
		return 0;
	}
	howManyRecords = importWeatherDataFile(textFile, arr, RECORDS_MAX);
	//getMenuOption();
	showMenu(arr, howManyRecords);
	fclose(textFile);
	return 0;
}