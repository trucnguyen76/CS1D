/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #8: Double Hashing
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/17/15
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include "HashTable.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

/**************************************************************************
 * PrintHeader
 * 	This function receives the programmer's name, assignment name, type
 * 		 and number then outputs the appropriate header
 * 		 -> return class headings
 ************************************************************************/
string PrintHeader(	string  programmer,	//IN 		- programmer(s)'s name
					char 	asType, 	//IN 		- assignment type
					string 	asName,		//IN & OUT 	- assignment name
					int 	asNum);		//IN & OUT 	- assignment number

#endif




