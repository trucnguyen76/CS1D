#include "header.h"

int main()
{

	priority_queue<Patient> patientQueue2;

	PriorityQueue<Patient> patientQueue;
	Patient nextPerson;
	Patient personGoesIn;

	patientQueue.insert(Patient("Alice", 3));
	patientQueue.insert(Patient("Irene Ill", 1));
	patientQueue.insert(Patient("Sid Sickly", 4));
	patientQueue.insert(Patient("Cathy Coughing", 5));
	patientQueue.insert(Patient("Bob Bleeding", 2));
	patientQueue.print();

	patientQueue.insert(Patient("Frank Feelingbad", 7));
	patientQueue.print();

	patientQueue.insert(Patient("Sam Sneezing", 5));

	patientQueue.print();

	removePatient(patientQueue);
	removePatient(patientQueue);
	removePatient(patientQueue);

	patientQueue.insert(Patient("Paula Pain", Patient::EMERGENCY));

	removePatient(patientQueue);
	removePatient(patientQueue);

	patientQueue.insert(Patient("Tom Temperature", Patient::EMERGENCY));

	removePatient(patientQueue);
	removePatient(patientQueue);
	removePatient(patientQueue);
	removePatient(patientQueue);

	return 0;
}

