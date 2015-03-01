#include "Patient.h"
#include "PriorityQueue.h"

#include <iostream>
#include <iomanip>

using namespace std;

void removePatient(PriorityQueue<Patient>& patientQueue)
										//IN & OUT - Patient List
{
	Patient personGoesIn, nextPerson;

	patientQueue.removeMin(personGoesIn);
	personGoesIn.print();
	cout << ", please come up\n\n";

	cout << "The list is now: " << endl;
	patientQueue.print();

	cout << "Next person in line is: ";
	nextPerson = patientQueue.min();
	nextPerson.print();
	cout << endl << endl;
}


