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



#pragma once

#ifndef FILE_READING_H
#define FILE_READING_H


//STRUCTURES DECLARATION


struct Date
{
	int year;
	int month;
};


struct Location
{
	int regionCode;
	char name[20];
};


struct WeatherRecord
{
	struct Date     date;
	double	        precipAmt;
	char            unit;
	struct Location location;
};

struct Region
{
	int regionDirection;
	char regionName[20];
	double totalRegion;
};


struct Month
{
	char nameMonth[15];
	int totalMonth;
};

struct Area
{
	char regionName[20];
	double totalPercip;
};
//FUNCTION PROTOTYPES 

int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max);




#endif // !FILE_READING_H1