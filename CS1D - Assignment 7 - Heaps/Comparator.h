/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #7: Heap
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/10/15
 *************************************************************************/
template <class Type>
class Comparator
{
public:
	bool operator()(const Type& p, const Type& q) const;
};

template <class Type>
bool Comparator<Type>::operator()(const Type& p, const Type& q) const
{
	return p < q;
}


