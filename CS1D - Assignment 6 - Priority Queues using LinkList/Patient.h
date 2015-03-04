/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #6: Priority Queue
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/3/15
 *************************************************************************/
#ifndef PATIENT_H_
#define PATIENT_H_
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Patient
{
public:
	static const int EMERGENCY = 10000;

	Patient();

	Patient(string patientName);
	Patient(string patientName, int hours);

	~Patient();

	void setName(string patientName);
	void setHours(int waitingHours);

	string 	getName()  const;
	int 	getHours() const ;

	void    print()		const;

	Patient& operator =   (const Patient& otherPatient);
	int 	 operator >   (const Patient& otherPatient)	const;
	int 	 operator >=  (const Patient& otherPatient) const;
	int 	 operator <   (const Patient& otherPatient) const;
	int 	 operator <=  (const Patient& otherPatient) const;
	int 	 operator ==  (const Patient& otherPatient) const;

private:
	string  name;
	int 	hoursWaiting;
};

#endif




