/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #7: Heap
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/10/15
 *************************************************************************/
#include "header.h"

int main()
{
	/**************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------
	 * INPUT 		: The array of inputs
	 * ARRAY_SIZE 	: The array size of the input array
	 *************************************************************/
	const int INPUT[] = {67, 88, 77, 52, 44, 11, 66, 93};
	const int ARRAY_SIZE = 8;

	Heap<int> heap1;
	HeapWithComparator<int, Comparator<int> > heap2;
	int minItem;		//CALC - The minimum item of the heap
	int index;			//CALC - The index of the element in the array

	cout << PrintHeader("Elva Nguyen", 'a', "Heaps", 7);

	for(index = 0; index < ARRAY_SIZE; index++)
	{
		cout << "Inserting " << INPUT[index] << endl;
		heap1.insert(INPUT[index]);
		cout << "Heap 1 is: ";
		heap1.print();

		heap2.insert(INPUT[index]);
		cout << "Heap 2 is: ";
		heap2.print();
	}

	while(heap1.size() > 0 || heap2.size() > 0)
	{
		minItem = -1;
		minItem = heap1.min();
		cout <<"Removing " << minItem << endl;
		heap1.removeMin();
		heap2.removeMin();
		cout << "Heap 1 is: ";
		heap1.print();
		cout << "Heap 2 is: ";
		heap2.print();
	}
	return 0;
}
