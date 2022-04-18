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


int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max)
{
	int recs = 0;

	if (fp != NULL)
	{
		while (recs < max &&
			fscanf(fp, "%d,%d, %lf, %c, %d, %15[^\n]\n",
				&data[recs].date.year, &data[recs].date.month,
				&data[recs].precipAmt, &data[recs].unit,
				&data[recs].location.regionCode,
				&data[recs].location.name) == 6)
		{
			recs++;
		}
	}
	return recs;
}