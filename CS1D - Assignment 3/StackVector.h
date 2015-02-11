/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #3: Stack and Deque
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 2/10/15
 *************************************************************************/
#include <vector>

using namespace std;

#ifndef STACK_VECTOR_H_
#define STACK_VECTOR_H_


template <class Type>
class StackVector: public vector<Type>
{
public:
    bool isEmptyStack();
    void push(const Type& newItem);
    void pop(Type& poppedElement);
    void destroyStack();
    void front(Type& frontElement);
    void print();
    StackVector();
    StackVector(const StackVector<Type>& otherStack);
    ~StackVector();
};

template <class Type>
StackVector<Type>::StackVector() : vector<Type>::vector() {}

template <class Type>
StackVector<Type>::StackVector(const StackVector<Type>& otherStack)
		:vector<Type>::vector(otherStack){}

template <class Type>
StackVector<Type>::~StackVector()
{
	vector<Type>::clear();
}

template <class Type>
bool StackVector<Type>::isEmptyStack()
{
	return vector<Type>::empty();
}

template <class Type>
void StackVector<Type>::push(const Type& newItem)
{

	vector<Type>::insert(vector<Type>::begin(), newItem);
}

template <class Type>
void StackVector<Type>::pop(Type& poppedElement)
{
	poppedElement = vector<Type>::at(0);
	vector<Type>::erase(vector<Type>::begin());
}

template <class Type>
void StackVector<Type>::destroyStack()
{
	vector<Type>::clear();
}


template <class Type>
void StackVector<Type>::front(Type& frontElement)
{
	frontElement = vector<Type>::front();
}

template <class Type>
void StackVector<Type>::print()
{
	unsigned index = 0;

	while(index < vector<Type>::size())
	{
		cout << vector<Type>::at(index);

		cout << " ";
		index++;
	}

}


#endif //STACK_VECTOR_H

