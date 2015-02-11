/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #3: Stack and Deque
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 2/10/15
 *************************************************************************/
#include "linklist.h"

#ifndef LINKED_DEQUE_H_
#define LINKED_DEQUE_H_

template <class Type>
class LinkedDeque: public LinkList<Type>
{
public:
	LinkedDeque();
	LinkedDeque(const LinkList<Type>& anotherDeque);
	~LinkedDeque();

	void insertFront(Type item);	//IN  - The item being inserted
	void insertBack	(Type item);	//IN  - The item being inserted
	void removeFront(Type& item);	//OUT - The item in front
	void removeBack (Type& item);	//OUT - The item in back
	void front		(Type& item);	//OUT - The item in front
	void back		(Type& item);	//OUT - The item in the back
	void destroyDeque();
	bool isEmpty();
	int  size();
	void print();
};

template <class Type>
LinkedDeque<Type>::LinkedDeque() : LinkList<Type>::LinkList(){}

template <class Type>
LinkedDeque<Type>::LinkedDeque(const LinkList<Type>& anotherDeque)
: LinkList<Type>::LinkList(anotherDeque){}

template <class Type>
LinkedDeque<Type>::~LinkedDeque()
{
	destroyDeque();
}

template <class Type>
void LinkedDeque<Type>::insertFront(Type item)	//IN  - The item being inserted
{
	LinkList<Type>::insertFirst(item);
}

template <class Type>
void LinkedDeque<Type>::insertBack(Type item)	//IN  - The item being inserted
{
	LinkList<Type>::insertLast(item);
}

template <class Type>
void LinkedDeque<Type>::removeFront(Type& item)	//OUT - The item in front
{
	LinkList<Type>::deleteFirst(item);
}
template <class Type>
void LinkedDeque<Type>::removeBack(Type& item)	//OUT - The item in back
{
	LinkList<Type>::deleteLast(item);
}

template <class Type>
void LinkedDeque<Type>::front(Type& item)	//OUT - The item in front
{
	LinkList<Type>::retrieveFront(item);
}
template <class Type>
void LinkedDeque<Type>::back(Type& item)	//OUT - The item in front
{
	LinkList<Type>::retrieveBack(item);
}
template <class Type>
void LinkedDeque<Type>::destroyDeque()
{
	LinkList<Type>::destroyList();
}

template <class Type>
bool LinkedDeque<Type>::isEmpty()
{
	return LinkList<Type>::isEmpty();
}

template <class Type>
int LinkedDeque<Type>::size()
{
	return LinkList<Type>::getSize();
}

template <class Type>
void LinkedDeque<Type>::print()
{
	int index;		//CALC - The index of the item
	int size;		//CALC - The size of the list
	Type item;		//CALC - The item at the index position

	index = 0;
	size = LinkList<Type>::getSize();

	while(index < size)
	{
		LinkList<Type>::retrieve(index, item);

		cout << item;
		cout << " ";

		index++;
	}
}

#endif
