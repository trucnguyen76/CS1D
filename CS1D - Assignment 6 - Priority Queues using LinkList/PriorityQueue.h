#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include "orderedlinklist.h"

template <class Type>
class PriorityQueue : private OrderedLinkList<Type>
{
public:
    /*****************************************************************************
    * PriorityQueue()
    * 	This constructor will create an empty linked list
    *****************************************************************************/
    PriorityQueue();

    /*****************************************************************************
    * PriorityQueue()
    * 	This copy constructor will create a list from another list
    *****************************************************************************/
    PriorityQueue(const PriorityQueue<Type> &otherList);

    /*****************************************************************************
    * ~PriorityQueue()
    * 	This destructor will destroy the LinkedList object
    *****************************************************************************/
    ~PriorityQueue();

    /*****************************************************************************
    * insert()
    * 	This method will insert the newItem to the the specified position of the
    * 	 list and push back the rest of the list
    * 	-> Return nothing
    * 	POST: The item being added to the list
    *****************************************************************************/
    void insert(const Type& newItem);	//IN - The newItem being added to the list

    /*****************************************************************************
    * destroyList()
    * 	This method will clear the list
    * 	-> Return nothing
    * 	POST: 	first-> null
    * 			last -> null
    *****************************************************************************/
    void destroyList();

    /*************************************************************************
     * isEmpty
     *		This method checks if the queue is empty or not
     *		-> RETURN a bool indicates whether the queue is empty or not
     ************************************************************************/
    bool isEmpty()							const;

    /*************************************************************************
     * min()
     *		This method will return the minimum of the list
     *		-> RETURN the minimum of the list
     ************************************************************************/
    Type min();

    /*************************************************************************
     * size
     *		This method returns the size of the queue
     *		-> RETURN the size of the queue as an integer
     ************************************************************************/
    int  getSize()							const;

    /*****************************************************************************
    * removeMin()
    * 	This method will remove the first item of the list
    * 	-> Return the deleteItem through the parameter
    * 	POST:	the first item is removed from the list
    *****************************************************************************/
    void removeMin(Type& deleteItem);	//OUT - The item being deleted

    void print();

};

template <class Type>
PriorityQueue<Type>::PriorityQueue() :
					OrderedLinkList<Type>::OrderedLinkList(){}

template <class Type>
PriorityQueue<Type>::PriorityQueue(const PriorityQueue& otherQueue) :
					OrderedLinkList<Type>::OrderedLinkList(otherQueue){}

template <class Type>
PriorityQueue<Type>::~PriorityQueue()
{
	OrderedLinkList<Type>::~OrderedLinkList();
}

template <class Type>
void PriorityQueue<Type>::destroyList()
{
	OrderedLinkList<Type>::destroyList();
}

template <class Type>
bool PriorityQueue<Type>::isEmpty()							const
{
	return OrderedLinkList<Type>::isEmpty();
}

template <class Type>
Type PriorityQueue<Type>::min()
{
	if(!isEmpty())
	{
		return OrderedLinkList<Type>::retrieveFirst();
	}
	else
	{
		cout << "The list is empty. There is no min\n";
		return Type();
	}
}

template <class Type>
int  PriorityQueue<Type>::getSize()							const
{
	return OrderedLinkList<Type>::getSize();
}

template <class Type>
void PriorityQueue<Type>::removeMin(Type& deleteItem)
{
	OrderedLinkList<Type>::deleteFirst(deleteItem);
}

template <class Type>
void PriorityQueue<Type>::insert(const Type& newItem)
{
	OrderedLinkList<Type>::insert(newItem);
}

template <class Type>
void PriorityQueue<Type>::print()
{
	int index = 0;
	while(index < LinkList<Type>::getSize())
	{
		(OrderedLinkList<Type>::retrieve(index)).print();
		cout << endl;

		index++;
	}
	cout << endl;
}



#endif




