/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #8: Double Hashing
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/17/15
 *************************************************************************/
#include "header.h"

int main()
{
	Pair<int, string> pair;
	HashTable<int, string> table;
	ifstream inFile;
	int key;
	string value;

	cout << PrintHeader("Elva Nguyen", 'a', "Double Hashing", 8);

	inFile.open("inFile.txt");

	while(inFile)
	{
//		cout << "In while \n";
		value = "";
		inFile >> key;
		getline(inFile, value);

		if(value != "")
		{
			pair.setKey(key);
			pair.setValue(value);

			cout << "Inserting key " << key << ": " << endl;
			table.insert(pair);
			table.print();
		}
		else
		{
			cout << "Delete key " << key << ": " << endl;
			table.deleteItem(key);
			table.print();
		}

//		cin.ignore(100, '\n');
	}

	inFile.close();

//	cout << "End\n";
//	cin.ignore(1000, '\n');

	return 0;
}

