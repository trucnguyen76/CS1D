/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #6: Priority Queue
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/3/15
 *************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include "Patient.h"
#include "PriorityQueue.h"
#include <queue>

using namespace std;

/**************************************************************************
 * removePatient
 * 	This function receives a priority Queue of patient and an int represents
 * 		the minutes since 12: 00. Then it will remove the patient in front
 * 		of the queue and output the remaining people in the list.
 ************************************************************************/
void removePatient(PriorityQueue<Patient>&  patientQueue, //IN & OUT - Patient List
										int time);		  //IN 		 - Current time

void removePatient(priority_queue<Patient>&  patientQueue, //IN & OUT- Patient List
										int time);		  //IN 		 - Current time

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
