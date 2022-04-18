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

// macrios
#define NAME_LENGTH 20
#define REGION_LENGTH 20
#define MONTH_LENGTH 15

// ================== Structures ==================

struct Date
{
	int year;
	int month;
};

struct Location
{
	int regionCode;
	char name[NAME_LENGTH];
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
	char regionName[REGION_LENGTH];
	double totalRegion;
};

struct Month
{
	char nameMonth[MONTH_LENGTH];
	int totalMonth;
};

struct Area
{
	char regionName[REGION_LENGTH];
	double totalPercip;
};

// ================== Function Protypes ==================

int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max);

#endif // !FILE_READING_H1