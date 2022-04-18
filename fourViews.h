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
#ifndef FOURVIEWS_H
#define FOURVIEWS_H

//utility functions
void clearInputBuffer(void);
void suspend(void);
int inputIntRange(int low, int high);


//conver cm to mmm
int conversionResult(struct WeatherRecord arr[], int howManyRecords);

//***VIEW#2 
//sum by region
void summaryRegion(struct WeatherRecord arr[], int howManyRecords,
	double* WesternTotal,
	double* EasternTotal,
	double* NorthenTotal,
	double* CentralTotal);



void sortByRegion(struct Region r[], int n);


//***VIEW#3
// sum by month
void summaryMonth(struct WeatherRecord arr[], int howManyRecords,
	int* TotalJanuary, int* TotalFebruary, int* TotalMarch,
	int* TotalApril, int* TotalMay, int* TotalJune, int* TotalJule,
	int* TotalAugust, int* TotalSeptember, int* TotalOctober,
	int* TotalNovember, int* TotalDecember);


//sort 
void sortByMonth(struct Month m[], int b);









//***VIEW#4



void locationSummary(struct WeatherRecord arr[], int howManyRecords,
	double* chathamPercip,
	double* haltonPercip,
	double* renfrewPercip,
	double* kenoraPercip,
	double* simcoePercip,
	double* essexPercip,
	double* ottawaPercip,
	double* thunderBayPercip);


void sortByLocationName(struct Region r[], int n);






#endif // !FOURVIEWS_H1