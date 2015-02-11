/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #3: Stack and Deque
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 2/10/15
 *************************************************************************/
#include "link5.h"

template <class Type>
class linkedStackType : public linkedListType<Type>
{
public:
	linkedStackType();

    const linkedStackType<Type>& operator=
                                (const linkedStackType<Type>& otherStack);
    void initializeStack();
    bool isEmptyStack();
    bool isFullStack();
    void push(const Type& newItem);
    void pop(Type& poppedElement);
    void destroyStack();
    void front(Type& frontElement);
    linkedStackType(const linkedStackType<Type>& otherStack);
    ~linkedStackType();


private:
static const int CAPACITY = 10;
};

template <class Type>
linkedStackType<Type>::linkedStackType() : linkedListType<Type>::linkedListType() {}

template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack)
		:linkedListType<Type>::linkedListType(otherStack){}

template <class Type>
linkedStackType<Type>::~linkedStackType()
{
	destroyStack();
}

template <class Type>
void linkedStackType<Type>::initializeStack()
{
	linkedListType<Type>::initializeList();
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack()
{
	return linkedListType<Type>::isEmptyList();
}

template <class Type>
bool linkedStackType<Type>::isFullStack()
{
	int count;				//CALC - Counter for element
	nodeType<Type> *nodePtr;	//CALC - Auxiliary pointer

	nodePtr = linkedListType<Type>::first;
	count = 0;

	while(nodePtr != NULL)
	{
		count++;
		nodePtr = nodePtr->link;
	}

	return count == CAPACITY;

}

template <class Type>
void linkedStackType<Type>::push(const Type& newItem)
{
	if(!isFullStack())
	{
		linkedListType<Type>::insertFirst(newItem);
	}
}

template <class Type>
void linkedStackType<Type>::pop(Type& poppedElement)
{
	linkedListType<Type>::retrieveFirst(poppedElement);
	linkedListType<Type>::deleteNode(poppedElement);
}

template <class Type>
void linkedStackType<Type>::destroyStack()
{
	linkedListType<Type>::destroyList();
}

template <class Type>
const linkedStackType<Type>& linkedStackType<Type>:: operator=
                            (const linkedStackType<Type>&otherStack)
{
	linkedListType<Type>::operator=(otherStack);
	return *this;
}

template <class Type>
void linkedStackType<Type>::front(Type& frontElement)
{
	linkedListType<Type>::retrieveFirst(frontElement);
}










