/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #6: Priority Queue
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/3/15
 *************************************************************************/
#include "Patient.h"
#include "PriorityQueue.h"

#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

/**************************************************************************
 *
 * FUNCTION removePatient
 * ________________________________________________________________________
 * 	This function receives a priority Queue of patient and an int represents
 * 		the minutes since 12: 00. Then it will remove the patient in front
 * 		of the queue and output the remaining people in the list.
 * ________________________________________________________________________
 * PRE-CONDITIONS
 *		patientQueue	: patient list has to be pre-defined
 *		time			: minutes since 12: 00 has to be pre-defined
 *
 * POST-CONDITIONS
 * 		This function remove the first person in the patientQueue and return
 * 			the list through the parameter. This function will also
 * 			print the list of remaining patients
 ************************************************************************/
void removePatient(PriorityQueue<Patient>&  patientQueue, //IN & OUT - Patient List
										int time)		  //IN 		 - Current time
{
	Patient personGoesIn;	//OUT - The person that goes in
	Patient nextPerson;		//OUT - The next person in line
	int hour;				//OUT - The hour of current time
	int minute;				//OUT - The minute of current time

	hour 	= time / 60;
	minute 	= time % 60;

	patientQueue.removeMin(personGoesIn);
	if(hour < 10)
	{
		cout << "0";
	}
	cout << hour << ":";
	if(minute < 10)
	{
		cout << "0";
	}
	cout << minute << endl;
	personGoesIn.print();
	cout << ", please come up\n\n";

//	if(!patientQueue.isEmpty())
//	{
//		cout << "The list is now: " << endl;
//		patientQueue.print();
//
//		cout << "Next person in line is: ";
//		nextPerson = patientQueue.min();
//		nextPerson.print();
//		cout << endl << endl;
//	}
//	else
//	{
//		cout << "The list is empty. There is nobody in the list\n";
//	}


}

void removePatient(priority_queue<Patient>&  patientQueue, //IN & OUT- Patient List
										int time)		  //IN 		 - Current time
{
	Patient personGoesIn;	//OUT - The person that goes in
	Patient nextPerson;		//OUT - The next person in line
	int hour;				//OUT - The hour of current time
	int minute;				//OUT - The minute of current time

	hour 	= time / 60;
	minute 	= time % 60;

	personGoesIn = patientQueue.top();
	patientQueue.pop();
	if(hour < 10)
	{
		cout << "0";
	}
	cout << hour << ":";
	if(minute < 10)
	{
		cout << "0";
	}
	cout << minute << endl;
	personGoesIn.print();
	cout << ", please come up\n\n";
//
//	if(!patientQueue.empty())
//	{
//
//		cout << "Next person in line is: ";
//		nextPerson = patientQueue.top();
//		nextPerson.print();
//		cout << endl << endl;
//	}
//	else
//	{
//		cout << "The list is empty. There is nobody in the list\n";
//	}


}


