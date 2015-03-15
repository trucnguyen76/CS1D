/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #8: Double Hashing
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/17/15
 *************************************************************************/
#ifndef PAIR_H_
#define PAIR_H_

#include <iostream>

using namespace std;

template <class Key, class Value>
class Pair
{
public:
	Pair();
	Pair(Key pairKey,
		 Value pairValue);

	Pair(const Pair<Key, Value>& anotherPair);
	~Pair();
	void setKey(Key pairKey);
	void setValue(Value pairValue);
	Key getKey()	const;
	Value getValue()  const;

private:
	Key key;
	Value value;
};

template <class Key, class Value>
Pair<Key, Value>::Pair()
{
//	cout << "Pair constructor\n";
//	cin.ignore(100, '\n');
	key = -1;
	value = "";
}

template <class Key, class Value>
Pair<Key, Value>::	Pair(Key pairKey, Value pairValue)
{
	key = pairKey;
	value = pairValue;
}

template <class Key, class Value>
Pair<Key, Value>::	Pair(const Pair<Key, Value>& anotherPair)
{
	key = anotherPair.key;
	value = anotherPair.value;
}

template <class Key, class Value>
Pair<Key, Value>::~Pair()
{
//	cout << "Pair destructor\n";
//	cin.ignore(1000, '\n');
}

template <class Key, class Value>
void Pair<Key, Value>::setKey(Key pairKey)
{
	key  = pairKey;
}

template <class Key, class Value>
void Pair<Key, Value>::setValue(Value pairValue)
{
	value = pairValue;
}

template <class Key, class Value>
Key Pair<Key, Value>::getKey()	const
{
	return key;
}

template <class Key, class Value>
Value Pair<Key, Value>::getValue()  const
{
	return value;
}


#endif

