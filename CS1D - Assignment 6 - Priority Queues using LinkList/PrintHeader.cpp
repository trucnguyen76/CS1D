/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #6: Priority Queue
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/3/15
 *************************************************************************/
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;
/**************************************************************************
 *
 * FUNCTION PrintHeader
 * ________________________________________________________________________
 * 	This function receives the programmer's name, assignment name, type
 * 		 and number then outputs the appropriate header
 * 		 -> return class headings
 * ________________________________________________________________________
 * PRE-CONDITIONS
 *		programmer	: Programmer(s)'s name has to be previously defined
 *		asName		: Assignment Name has to be previously defined
 *		asType		: Assignment Type has to be previously defined
 *		asNum		: Assignment Number has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will return the class heading
 ************************************************************************/
string PrintHeader(	string  programmer,	//IN 		- programmer(s)'s name
					char 	asType, 	//IN 		- assignment type
					string 	asName,		//IN & OUT 	- assignment name
					int 	asNum)		//IN & OUT 	- assignment number
{
	/**********************************************************************
	 * CONSTANTS
	 * --------------------------------------------------------------------
	 * CLASS      		: Student's Course
	 * SECTION    		: Class Days and Times
	 * LINE_LENGTH		: The Maximum Length of a line
	 *********************************************************************/
	const char CLASS[5]       		= "CS1D";
	const char SECTION[25]    		= "T-Th: 5:30 - 9:20p";
	const int  LINE_LENGTH 			= 75;

	ostringstream output; //CALC - ostringstream variable to return a string

	// OUTPUT - Class Heading
	output << left;
	output << setfill('*');
	output << setw(LINE_LENGTH) << '*';
	output << setfill(' ');
	output << "\n*  PROGRAMMED BY : " << programmer;
	output << "\n*  " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n*  " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n*  ";
	if (toupper(asType) == 'L')
	{
		output << "LAB #" << setw(9);
	}
	else
	{
		output << "ASSIGNMENT #" << setw(2);
	}
	output << asNum << ": " << asName << endl;
	output << setfill('*');
	output << setw(LINE_LENGTH) << '*' << endl << endl;
	output.fill(' ');
	output << right;

	return output.str();
}

