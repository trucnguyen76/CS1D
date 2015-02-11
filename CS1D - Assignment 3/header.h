/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #3: Stack and Deque
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 2/10/15
 *************************************************************************/
#ifndef HEADER_H
#define HEADER_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "StackVector.h"
#include "linkedStack.h"
#include "linkedDeque.h"


using namespace std;

/**************************************************************************
 * PrintHeader
 * 		This function receives the programmer's name, assignment name, type
 * 		 and number then outputs the appropriate header
 * 		 -> return class headings
 ************************************************************************/
string PrintHeader(	string  programmer,	//IN 		- programmer(s)'s name
					char 	asType, 	//IN 		- assignment type
					string 	asName,		//IN & OUT 	- assignment name
					int 	asNum);		//IN & OUT 	- assignment number

/**************************************************************************
 * ParenThesesMatching
 * 		This function receives the character array and the array size. Then
 * 			it will return a bool value indicates whether the parentheses
 * 			match
 * 		 -> return bool value indicates whether the parentheses match
 ************************************************************************/
bool ParenthesesMatching(const char array[],	//IN  - The array of character
								int arraySize);	//OUT - The size of the array

double EvaluateExpression(const string str);

double Convert(string str);

string Convert(double num);

string Convert(char character);


#endif //HEADER_H
