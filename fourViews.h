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

// ================== Utility Functions ==================

void clearInputBuffer(void);
void suspend(void);
int inputIntRange(int low, int high);

// ================== Conversion Functions ==================

int conversionResult(struct WeatherRecord arr[], int howManyRecords);
int reverseConversion(struct WeatherRecord arr[], int howManyRecords);

// ================== VIEW #1 - All Data ==================

void viewAllData(struct WeatherRecord arr[], int howManyRecords);

// ================== VIEW #2 - By Region ==================

void viewByRegion(struct WeatherRecord arr[], int howManyRecords);
void summaryRegion(struct WeatherRecord arr[], int howManyRecords,
	double* totalWestern,
	double* totalEastern,
	double* totalNorthern,
	double* totalCentral);

void sortByRegion(struct Region r[], int n);


// ================== VIEW #3 - By Month ==================

void viewByMonth(struct WeatherRecord arr[], int howManyRecords);
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
	int* totalDecember);

void sortByMonth(struct Month m[], int b);

// ================== VIEW #4 - By Location ==================
void viewByLocation(struct WeatherRecord arr[], int howManyRecords);
void locationSummary(struct WeatherRecord arr[], int howManyRecords, 
	double* totalChatham,
	double* totalHalton,
	double* totalRenfrew,
	double* totalKenora,
	double* totalSimcoe,
	double* totalEssex,
	double* totalOttawa,
	double* totalThunderBay);

void sortByLocationName(struct Area r[], int n);

#endif // !FOURVIEWS_H1