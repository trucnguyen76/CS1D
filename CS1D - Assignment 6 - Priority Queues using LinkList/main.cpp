/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #6: Priority Queue
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/3/15
 *************************************************************************/
#include "header.h"
/**************************************************************************
 *
 * Hospital
 * ________________________________________________________________________
 * 	This method will output whoever turns to see the doctor based on a
 * 		priority queue
 * ________________________________________________________________________
 * INPUT:
 * 		<none>
 *
 * OUTPUT:
 * 		nextPerson		:	The person that is next in line
 * 		personGoesIn	:	The person who's called to see the doctor
 ************************************************************************/
int main()
{
	priority_queue<Patient> patientQueue2;	//OUT  - The STL Priority Queue
	PriorityQueue<Patient> patientQueue;	//OUT  - The Priority Queue
	Patient nextPerson;						//OUT  - Next person in line
	Patient personGoesIn;					//OUT  - Person coming in now
	bool emergency;							//CALC - Indicate if there is an emer
	int timer;								//CALC - The timer for each person
	int clock;								//CALC - The clock for the current time
	int emergencyTimer;						//CALC - The timer for emer patient

	timer = 0;
	clock = 0;
	emergencyTimer = 0;
	emergency = false;

	//Class Headings
	cout << PrintHeader ("Elva Nguyen", 'a', "Priority Queue", 6);

	cout << "PART 1: IMPLEMENTING PRIORITY QUEUE\n\n";

	patientQueue.insert(Patient("Alice", 3));
	patientQueue.insert(Patient("Irene Ill", 1));
	patientQueue.insert(Patient("Sid Sickly", 4));
	patientQueue.insert(Patient("Cathy Coughing", 5));
	patientQueue.insert(Patient("Bob Bleeding", 2));
	patientQueue.insert(Patient("Frank Feelingbad", 7));
	patientQueue.insert(Patient("Sam Sneezing", 5));

	//While loop - Removing a patient every 30 minutes
	while(!patientQueue.isEmpty())
	{
		//At 1:30 -> 90 mins after 12:00
		if(clock == 90)
		{
			patientQueue.insert(Patient("Paula Pain", Patient::EMERGENCY));
			emergency = true;
		}
		//At 2:10 -> 130 mins after 12:00
		if(clock == 130)
		{
			patientQueue.insert(Patient("Tom Temperature", Patient::EMERGENCY));
			emergency = true;
		}
		if(!emergency)
		{
			//Reset the timer every 30 minutes
			if(timer == 30)
			{
				timer = 0;
			}
			//Every 30 minutes, pop a person
			if(timer == 0)
			{
				personGoesIn = patientQueue.min();
				removePatient(patientQueue, clock);
			}

			timer++;
		}
		else
		{
			if(emergencyTimer == 30)
			{
				emergencyTimer = 0;
				emergency = false;
				if((clock / 60) < 10)
				{
					cout << "0";
				}
				cout << clock / 60 << ":";
				if((clock % 60) < 10)
				{
					cout << "0";
				}
				cout << (clock % 60) << endl;
				personGoesIn.print();
				cout << ", please come up\n\n";
			}
			if(emergencyTimer == 0 && emergency)
			{
				removePatient(patientQueue, clock);
			}

			if(emergency)
			{
				emergencyTimer++;
			}
		}
		clock ++;
	}
//********************************************************************************
	cout << setfill('*');
	cout << setw(50) << '*';
	cout << "\n\nPART 2: STL PRIORITY QUEUE\n\n";

	timer = 0;
	clock = 0;
	emergencyTimer = 0;

	patientQueue2.push(Patient("Alice", -3));
	patientQueue2.push(Patient("Irene Ill", -1));
	patientQueue2.push(Patient("Sid Sickly", -4));
	patientQueue2.push(Patient("Cathy Coughing", -5));
	patientQueue2.push(Patient("Bob Bleeding", -2));
	patientQueue2.push(Patient("Frank Feelingbad", -7));
	patientQueue2.push(Patient("Sam Sneezing", -5));

	//While loop - Removing a patient every 30 minutes
	while(!patientQueue2.empty())
	{
		//At 1:30 -> 90 mins after 12:00
		if(clock == 90)
		{
			patientQueue2.push(Patient("Paula Pain", -Patient::EMERGENCY));
			emergency = true;
		}
		//At 2:10 -> 130 mins after 12:00
		if(clock == 130)
		{
			patientQueue2.push(Patient("Tom Temperature", -Patient::EMERGENCY));
			emergency = true;
		}
		if(!emergency)
		{
			//Reset the timer every 30 minutes
			if(timer == 30)
			{
				timer = 0;
			}
			//Every 30 minutes, pop a person
			if(timer == 0)
			{
				personGoesIn = patientQueue2.top();
				removePatient(patientQueue2, clock);
			}

			timer++;
		}
		else
		{
			if(emergencyTimer == 30)
			{
				emergencyTimer = 0;
				emergency = false;
				if((clock / 60) < 10)
				{
					cout << "0";
				}
				cout << clock / 60 << ":";
				if((clock % 60) < 10)
				{
					cout << "0";
				}
				cout << (clock % 60) << endl;
				personGoesIn.print();
				cout << ", please come up\n\n";
			}
			if(emergencyTimer == 0 && emergency)
			{
				removePatient(patientQueue2, clock);
			}

			if(emergency)
			{
				emergencyTimer++;
			}
		}
		clock ++;
	}

	return 0;
}

