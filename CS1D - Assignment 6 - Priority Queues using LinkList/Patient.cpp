#include "Patient.h"

Patient::Patient()
{
	name = "";
	hoursWaiting = 0;
}

Patient::Patient(string patientName)
{
	name = patientName;
	hoursWaiting = 0;
}

Patient::Patient(string patientName, int hours)
{
	name = patientName;
	hoursWaiting = hours;
}

Patient::~Patient(){}

void Patient::setName(string patientName)
{
	name = patientName;
}

void Patient::setHours(int waitingHours)
{
	hoursWaiting = waitingHours;
}

string Patient::getName()	const
{
	return name;
}

int Patient::getHours()		const
{
	return hoursWaiting;
}

Patient& Patient::operator =   (const Patient& otherPatient)
{
	name = otherPatient.name;
	hoursWaiting = otherPatient.hoursWaiting;

	return *this;
}

int 	 Patient::operator >   (const Patient& otherPatient) const
{
	return hoursWaiting < otherPatient.hoursWaiting;
}

int 	 Patient::operator >=  (const Patient& otherPatient) const
{
	return hoursWaiting <= otherPatient.hoursWaiting;
}

int 	 Patient::operator <   (const Patient& otherPatient) const
{
	return hoursWaiting > otherPatient.hoursWaiting;
}

int 	 Patient::operator <=  (const Patient& otherPatient) const
{
	return hoursWaiting >= otherPatient.hoursWaiting;
}

int 	 Patient::operator ==  (const Patient& otherPatient) const
{
	return hoursWaiting == otherPatient.hoursWaiting;
}

void Patient::print()			const
{
	cout << "Patient: "<< name << " - ";

	if(hoursWaiting == EMERGENCY)
	{
		cout << "EMERGENCY";
	}
	else
	{
		cout << hoursWaiting;
	}
}
