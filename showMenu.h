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

#ifndef SHOWMENU_H
#define SHOWMENU_H

#define STEPS 15; 
#include "file_reading.h"

//display a single record 
void displaySingleRecord(const struct WeatherRecord* arr);

//table headers 
void displayAllDataTableHeader(void);
void displayByRegionTableHeader(void);
void displayByMonthTableHeader(void);
void displayByLocationTableHeader(void);

//main Menu 
void showMenu(struct WeatherRecord arr[], int howManyRecords);

#endif // !SHOWMENU_H1