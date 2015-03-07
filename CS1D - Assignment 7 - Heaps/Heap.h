/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #7: Heap
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/10/15
 *************************************************************************/
#ifndef PRIORITY_HEAP_H_
#define PRIORITY_HEAP_H_

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//template <class Type>
//struct Node
//{
//	Type object;
//	Node<Type>* parent;
//	Node<Type>* left;
//	Node<Type>* right;
//};

template <class Type>
class Heap : public vector<Type>
{
public:
	Heap();

	Heap(const Heap& anotherQueue);

	~Heap();
    /*************************************************************************
     * isEmpty
     *		This method checks if the heap is empty or not
     *		-> RETURN a bool indicates whether the queue is empty or not
     ************************************************************************/
    bool isEmpty() const;

    /*****************************************************************************
    * insert()
    * 	This method will insert the insertItem to the heap and reorder the heap
    * 	-> Return nothing
    * 	POST: The item being added to the heap
    *****************************************************************************/
    void insert(const Type& insertItem);	//IN - Item being added to the heap

    /*************************************************************************
     * min()
     *		This method will return the minimum of the heap
     *		-> RETURN the minimum of the heap
     ************************************************************************/
    Type min()	const;

    /*****************************************************************************
    * removeMin()
    * 	This method will remove the min item of the heap
    * 	-> Return the deletedItem
    * 	POST:	the min item is removed from the heap
    *****************************************************************************/
    Type removeMin();

    /*****************************************************************************
    * print()
    * 	This method will output the vector heap
    * 	-> Return nothing
    * 	POST:	the heap is outputted
    *****************************************************************************/
    void print() const;

    /*************************************************************************
     * size
     *		This method returns the size of the heap
     *		-> RETURN the size of the heap as an integer
     ************************************************************************/
    int size() const;

protected:

    /*************************************************************************
     * at
     *		This method returns the reference of element at the specified index
     *		-> RETURN the size of the heap as an integer
     ************************************************************************/
    Type& at(int index);

    /*************************************************************************
     * at
     *		This method returns the element at the specified index
     *		-> RETURN the size of the heap as an integer
     ************************************************************************/
    Type at(int index)	const;
};
template <class Type>
Heap<Type>::Heap() : vector<Type>::vector(){}

template <class Type>
Heap<Type>::Heap(const Heap& anotherQueue)
				: vector<Type>::vector(anotherQueue){}

template <class Type>
Heap<Type>::~Heap()
{
	vector<Type>::~vector();
}

template <class Type>
bool Heap<Type>::isEmpty() const
{
    return size() == 0;
}

template <class Type>
int Heap<Type>::size() const
{
	int size;		//OUT - The size of the heap
	if (vector<Type>::size() > 0)
	{
//		cout << "In first part of if size\n";
		size = vector<Type>::size() - 1;
	}
	else
	{
		size = vector<Type>::size();
	}

	return size;
}

template <class Type>
Type& Heap<Type>:: at(int index)
{
	return vector<Type>::at(index);
}

template <class Type>
Type Heap<Type>:: at(int index)	const
{
	return vector<Type>::at(index);
}

template <class Type>
void Heap<Type>::insert(const Type& insertItem)
{
	int newItemIndex;		//CALC - The item's index
	int parentIndex;		//CALC - The item's parent's index
	Type emptyItem;			//CALC - The empty item added at index 0

	//If empty, create an empty node at index 0 cuz queue starts at 1
	if(isEmpty())
	{
		vector<Type>::push_back(emptyItem);
	}

	vector<Type>::push_back(insertItem);

	//New item will always be added to the end of the vector
	newItemIndex = vector<Type>::size() - 1;

	parentIndex = newItemIndex / 2;

	//If the insert element is less than its parent -> higher priority
	while(newItemIndex > 1 && insertItem < at(parentIndex))
	{
		vector<Type>::at(newItemIndex) = vector<Type>::at(parentIndex);
		vector<Type>::at(parentIndex)  = insertItem;

		newItemIndex = parentIndex;

		parentIndex /= 2;

	}
}

template <class Type>
Type Heap<Type>::min()	const
{
	if(!isEmpty())
	{
		//Use vector const_reference at() const function
		return vector<Type>::at(1);
	}
	else
	{
		cout << "Queue is empty. There is no min\n";
		return Type();
	}
}

template <class Type>
Type Heap<Type>::removeMin()
{
	class vector<Type>::iterator vectorIt;//CALC - Iterator of the vector
	Type minObject;						  //CALC - The minimum object
	Type movingItem;					  //CALC - The item being moved
	bool inOrder;						  //CALC - Indicate if heap is in order
	int lastIndex;						  //CALC - The last index of the vector
	int currentIndex;					  //CALC - The index of the current item
	int leftChildIndex;					  //CALC - The index of the left child
	int rightChildIndex;				  //CALC - The index of the right child

	inOrder 		= false;
	currentIndex 	= 1;
	leftChildIndex 	= currentIndex * 2;
	rightChildIndex = currentIndex * 2 + 1;
	lastIndex 		= vector<Type>::size() - 1;

	//Swap the element
	if(!isEmpty())
	{
		minObject = min();

		vector<Type>::at(1) =	vector<Type>::at(lastIndex);

		vectorIt = vector<Type>::end();
		vectorIt--;
		vector<Type>::erase(vectorIt);

		if(!isEmpty())
		{
			movingItem = min();
		}

		//Reorder the heap

		/*While loop - keep checking as long as there is a right element and
			the node is > element on the left and > element on the right
			(If there's a right element, there has to be a left element ) */
		while(	rightChildIndex < vector<Type>::size() && !inOrder)
		{
			if( at(currentIndex) > at(leftChildIndex)		&&
					at(currentIndex) > at(rightChildIndex))
			{
				//If left < right -> swap left with parent
				if(at(leftChildIndex) < at(rightChildIndex))
				{
					at(currentIndex) 	= at(leftChildIndex);
					at(leftChildIndex) 	= movingItem;

					currentIndex = leftChildIndex;
				}
				else
				{
					at(currentIndex) 	= at(rightChildIndex);
					at(rightChildIndex) = movingItem;

					currentIndex = rightChildIndex;
				}

				leftChildIndex 	= currentIndex * 2;
				rightChildIndex = currentIndex * 2 + 1;
			}
			else if(at(currentIndex) > at(leftChildIndex))
			{
				at(currentIndex) = at(leftChildIndex);
				at(leftChildIndex) = movingItem;

				currentIndex 	= leftChildIndex;
				leftChildIndex 	= currentIndex * 2;
				rightChildIndex = currentIndex * 2 + 1;
			}
			else if(at(rightChildIndex) > movingItem)
			{
				at(currentIndex) 	= at(rightChildIndex);
				at(rightChildIndex) = movingItem;

				currentIndex 	= rightChildIndex;
				leftChildIndex 	= currentIndex * 2;
				rightChildIndex = currentIndex * 2 + 1;
			}
			else
			{
				inOrder = true;
			}
		}// end while loop

		/*When the while loop exits, there are a few possibilities:
		 * 	The node has no left child
		 * 		-> the currentNode is external -> nothing else to do
		 * 	The node has left child but no right child
		 *
		 * 	size() is the size of the heap, not size of vector.
		 * 	size of heap is 1 less than size of vector
		 */

		if(!inOrder)
		{
			if(leftChildIndex < vector<Type>::size() &&
					at(leftChildIndex) < movingItem)
			{
				at(currentIndex) 	= at(leftChildIndex);
				at(leftChildIndex) 	= movingItem;
			}
		}
	}
	else
	{
		cout << "Queue is empty. There is no min\n";
		minObject = Type();
	}

	return minObject;
}

template <class Type>
void Heap<Type>::print() const
{
	int index;				//CALC - The index of the element in the vector

	if(isEmpty())
	{
		cout << "Heap is empty. There is nothing to print\n";
	}
	else
	{
		/*Start at one cuz realistically, we start storing at index 1 of vector
			Because size has been decrement 1 so that it match the heap size
			-> index <= size() or index < vector<Type>::size() */
		for(index = 1; index <= size(); index++)
		{
			cout << at(index);
			cout << "\t";
		}
		cout << endl;

	//	for(index = 1; index < size(); index++)
	//	{
	//		cout << vector<Type>::at(index);
	//		cout << endl;
	//		if(index != 1)
	//		{
	//			cout << "Parent of " << at(index) << " is " << at(index / 2);
	//			cout << endl;
	//		}
	//		cout << endl;
	//		if(index * 2 < size())
	//		{
	//			cout << "Left of " << at(index) << " is " << at(index * 2);
	//			cout << endl;
	//		}
	//		if(index * 2 + 1 < size())
	//		{
	//			cout << "Right of " << at(index) << " is " << at(index * 2 + 1);
	//			cout << endl;
	//		}
	//	}
	//	cout << endl;
	}


}
#endif

