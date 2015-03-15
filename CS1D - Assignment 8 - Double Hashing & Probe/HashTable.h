/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #8: Double Hashing
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/17/15
 *************************************************************************/
#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <vector>
#include "Pair.h"
#include <iostream>
#include <iomanip>
using namespace std;

//template <class Key, class Value>
//struct Pair1
//{
//	Key key;
//	Value value;
//};

template <class Key, class Value>
class HashTable : vector<Pair<Key, Value> >
{
public:
	HashTable();
	~HashTable();

	/**************************************************************************
	 * insert
	 * 	This method will insert a Pair item into the hash table
	 * 		-> return nothing
	 * 	POST: item is added into the hash table or error message if full
	 ************************************************************************/
	void insert(Pair<Key, Value> insertItem);

	/**************************************************************************
	 * deleteIem
	 * 	This method will delete Pair item with specifice key from the hash table
	 * 		-> return nothing
	 * 	POST: item is removed from the hash table or error message if not found
	 **************************************************************************/
	void deleteItem(Key key);

	/**************************************************************************
	 * isEmpty
	 * 	This method will check if the hash table is empty
	 * 		-> return bool indicate if the table is empty
	 **************************************************************************/
	bool isEmpty();

	/**************************************************************************
	 * size
	 * 	This method will return the number of element in the table
	 * 		-> return the size of the table
	 **************************************************************************/
	int size();

	/**************************************************************************
	 * firstHash
	 * 	This method will take the key and return the result after the first hash
	 * 		-> return the result of first hash
	 **************************************************************************/
	int firstHash(Key pairKey);

	/**************************************************************************
	 * secondHash
	 * 	This method will take the key and return the result after the 2nd hash
	 * 		-> return the result of second hash
	 **************************************************************************/
	int secondHash(Key pairKey);

	/**************************************************************************
	 * print
	 * 	This method will print the table
	 * 		-> return nothing
	 * 	POST: The table is printed
	 **************************************************************************/
	void print();

protected:
	/**************************************************************************
	 * search
	 * 	This method will search for the item that has the searchKey
	 * 		-> return the index of the item or -1 if not found
	 **************************************************************************/
	int search(const Key& searchKey);
private:
	int count;
	int arraySize = 19;
};

template <class Key, class Value>
HashTable<Key, Value>::HashTable() //: vector<Pair<Key, Value> >::vector()
{
	Pair<Key, Value> pair;
	typename vector<Pair<Key, Value> >::vector();
	for(int i = 0; i < arraySize; i++)
	{
		vector<Pair<Key, Value> >::push_back(pair);
	}
	count = 0;
//	cout << "Table constructor\n";
//	cin.ignore(100, '\n');
}

template <class Key, class Value>
HashTable<Key, Value>::~HashTable()
{
//	cout << "Table destructor\n";
//	cin.ignore(1000, '\n');
	vector<Pair<Key, Value> >::~vector();
}

template <class Key, class Value>
bool HashTable<Key, Value>::isEmpty()
{
	return count == 0;
}

template <class Key, class Value>
int HashTable<Key, Value>::size()
{
	return count;
}

template <class Key, class Value>
int HashTable<Key, Value>::firstHash(Key pairKey)
{
	return pairKey % arraySize;
}

template <class Key, class Value>
int HashTable<Key, Value>::secondHash(Key pairKey)
{
	return 17 - pairKey % 17;
}

template <class Key, class Value>
void HashTable<Key, Value>::insert(Pair<Key, Value> insertItem)
{
	int index;
	int hashingTimes = 0;
	typename vector<Pair<Key, Value> >::iterator vectorIt;

	index = firstHash(insertItem.getKey());

//	cout << "Before advance iterator\n";
//	cin.ignore(1000, '\n');
//	vectorIt = vector<Pair<Key, Value> >::begin();
//	for(int index= 0; i < index; i++)
//	{
//		vectorIt++;
//	}
//	cout << "After advance iterator\n";
//	cin.ignore(1000, '\n');

	if(vector<Pair<Key, Value> >::at(index).getKey() == -1 )
//	if(vectorIt->getKey() == -1 )
//		vector<Pair<Key, Value> >::at(index).getKey() == AVAILABLE)
	{
//		cout << "In if1\n";
//		cin.ignore(1000, '\n');

		vector<Pair<Key, Value> >::at(index).setKey(insertItem.getKey());
		vector<Pair<Key, Value> >::at(index).setValue(insertItem.getValue());
//		vectorIt->setKey(insertItem.getKey());
//		vectorIt->setValue(insertItem.getValue());


		count++;
	}
	//If the key already exists
	else if(vector<Pair<Key, Value> >::at(index).getKey() == insertItem.getKey() )
//	else if(vectorIt->getKey() == insertItem.getKey())
	{
//		cout << "In if2\n";
//		cin.ignore(1000, '\n');
		vector<Pair<Key, Value> >::at(index).setValue(insertItem.getValue());
	}
	else
	{
//		cout << "In if3\n";
//		cin.ignore(1000, '\n');
		while(vector<Pair<Key, Value> >::at(index).getKey() != -1 &&
				hashingTimes <= arraySize)
		{
			index = (firstHash(insertItem.getKey()) +
					hashingTimes * secondHash(insertItem.getKey())) % arraySize;

			hashingTimes++;
		}

		if(hashingTimes > arraySize)
		{
			cout << "Cannot insert. The Hash Table is full\n";
		}
		else
		{
//			vectorIt = vector<Pair<Key, Value> >::begin();
//			for(int i = 0; i < index; i++)
//			{
//				vectorIt++;
//			}

//			vectorIt->setKey(insertItem.getKey());
//			vectorIt->setValue(insertItem.getValue());

			vector<Pair<Key, Value> >::at(index).setKey(insertItem.getKey());
			vector<Pair<Key, Value> >::at(index).setValue(insertItem.getValue());
			count++;
		}
	}
}

template <class Key, class Value>
int HashTable<Key, Value>::search(const Key& searchKey)
{
	int index;
	int hashingTimes = 0;

	index = firstHash(searchKey);
	while(searchKey != vector<Pair<Key, Value> >::at(index).getKey() &&
			hashingTimes <= arraySize)
	{
		index = (firstHash(searchKey) +
				hashingTimes * secondHash(searchKey)) % arraySize;

		hashingTimes++;
	}

	if (hashingTimes > arraySize)
	{
//		cout  <<"There is no such key in the hash table\n";
		index = -1;
	}

	return index;
}

template <class Key, class Value>
void HashTable<Key, Value>::deleteItem(Key key)
{
	int index;
	typename vector<Pair<Key, Value> >::iterator vectorIt;

	index = search(key);

	if(index == -1)
	{
		cout << "Cannot delete. There is no such key in the hash table\n";
	}
	else
	{
//		vectorIt = vector<Pair<Key, Value> >::begin();
//		for(int i = 0; i < index; i++)
//		{
//			vectorIt++;
//		}

//		vectorIt->setKey(-1);

		vector<Pair<Key, Value> >::at(index).setKey(-1);

		count--;
	}
}

template <class Key, class Value>
void HashTable<Key, Value>::print()
{
	int index;

	cout << "Print: \n";

	for(index = 0; index < arraySize; index++)
	{
//		cout << "Index : " << index << '\t';
		if(vector<Pair<Key, Value> >::at(index).getKey() != -1)
		{
			cout << "Index : " << index << '\t';
			cout << vector<Pair<Key, Value> >::at(index).getKey();
			cout << " ";
			cout << vector<Pair<Key, Value> >::at(index).getValue();
			cout << endl;
		}

	}
}

#endif


