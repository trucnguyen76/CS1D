/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #3: Stack and Deque
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 2/10/15
 *************************************************************************/
#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
using namespace std;

//Definition of the node

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=
          			      (const linkedListType<Type>& otherList);
       //Overload the assignment operator
    void initializeList();
 	   //Initialize the list to an empty state
	   //Post: first = NULL, last = NULL
    bool isEmptyList();
	   //Function returns true if the list is empty;
	   //otherwise, it returns false
    void print();
	   //Output the data contained in each node
	   //Pre: List must exist
	   //Post: None
    int length();
	   //Return the number of elements in the list
    void destroyList();
	   //Delete all nodes from the list
	   //Post: first = NULL, last = NULL
    void retrieveFirst(Type& firstElement);
   	   //Return the info contained in the first node of the list
   	   //Post: firstElement = first element of the list
    void search(const Type& searchItem);
	   //Outputs "Item is found in the list" if searchItem is in
	   //the list; otherwise, outputs "Item is not in the list"
    void insertFirst(const Type& newItem);
	   //newItem is inserted in the list
	   //Post: first points to the new list and the
   	   //       newItem inserted at the beginning of the list
    void insertLast(const Type& newItem);
	   //newItem is inserted in the list
	   //Post: first points to the new list and the
   	   //     newItem is inserted at the end of the list
   	   //     last points to the last node in the list
    void deleteNode(const Type& deleteItem);
	   //if found, the node containing deleteItem is deleted
   	   //from the list
   	   //Post: first points to the first node and
       //  last points to the last node of the updated list
    linkedListType();
	   //default constructor
 	   //Initializes the list to an empty state
 	   //Post: first = NULL, last = NULL
    linkedListType(const linkedListType<Type>& otherList);
       //copy constructor
    ~linkedListType();
       //destructor
   	   //Deletes all nodes from the list
       //Post: list object is destroyed

protected:
    nodeType<Type> *first; //pointer to the first node of the list
    nodeType<Type> *last;  //pointer to the last node of the list
};


template<class Type>
bool linkedListType<Type>::isEmptyList()
{
	return(first == NULL);
}


template<class Type>
linkedListType<Type>::linkedListType() // default constructor
{
	first = NULL;
	last = NULL;
}

template<class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> *temp;   //pointer to deallocate the memory
							//occupied by the node
	while(first != NULL)    //while there are nodes in the list
	{
	   temp = first;        //set temp to the current node
	   first = first->link; //advance first to the next node
	   delete temp;         //deallocate memory occupied by temp
	}
	last = NULL;    //initialize last to NULL; first has already
                   //been set to NULL by the while loop
}


template<class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

template<class Type>
void linkedListType<Type>::print()
{
	nodeType<Type> *current; //pointer to traverse the list

	current = first;   //set current so that it points to
					   //the first node
	while(current != NULL) //while more data to print
	{
	   cout<<current->info <<" ";
	   current = current->link;
	}
}//end print



template<class Type>
int linkedListType<Type>::length()
{
	int count = 0;
  	nodeType<Type> *current; //pointer to traverse the list

	current = first;

	while (current!= NULL)
      {
	   count++;
	   current = current->link;
	}

 	return count;
}  // end length


template<class Type>
void linkedListType<Type>::retrieveFirst(Type& firstElement)
{
	if(!isEmptyList())
	firstElement = first->info; //copy the info of the first node
}//end retrieveFirst


template<class Type>
void linkedListType<Type>::search(const Type& item)
{
	nodeType<Type> *current; //pointer to traverse the list
	bool found;

	if(first == NULL)  //list is empty
		cout<<"Cannot search an empty list. "<<endl;
	else
	{
		current = first;  //set current pointing to the first
 		 				  //node in the list

		found = false;    //set found to false

		while(!found && current != NULL) //search the list
			if(current->info == item)      //item is found
       			found = true;
			else
				current = current->link; //make current point to
           								 //the next node

		if(found)
			cout<<"Item is found in the list."<<endl;
		else
			cout<<"Item is not in the list."<<endl;
   } //end else
}//end search

template<class Type>
void linkedListType<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode;		//pointer to create the new node

	newNode = new nodeType<Type>;	//create the new node
	newNode->info = newItem; 		//store the new item in the node
	newNode->link = first;			//insert newNode before first
	first = newNode;				//make first point to the
									//actual first node

	if(last == NULL)	//if the list was empty, newNode is also
						//the last node in the list
		last = newNode;
}


template<class Type>
void linkedListType<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem;      //store the new item in the node
    newNode->link = NULL;         //set the link field of new node
								  //to NULL

	if(first == NULL)  //if the list is empty, newNode is
     			    //both the first and last node
	{
		first = newNode;
		last = newNode;
	}
	else     //if the list is not empty, insert newNnode after last
	{
		last->link = newNode; //insert newNode after last
		last = newNode; //make last point to the actual last node
	}
}//end insertLast


template<class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;

	if(first == NULL)    //Case 1; list is empty.
		cout<<"Cannot delete from an empty list.\n";
	else
	{
		if(first->info == deleteItem) //Case 2
		{
			current = first;
			first = first ->link;
			if(first == NULL)    //list had only one node
				last = NULL;
			delete current;
		}
		else  //search the list for the node with the given info
		{
			found = false;
			trailCurrent = first;   //set trailCurrent to point to
									//the first node
			current = first->link;	//set current to point to the
    								//second node

			while((!found) && (current != NULL))
			{
  				if(current->info != deleteItem)
				{
					trailCurrent = current;
					current = current-> link;
				}
				else
					found = true;
			} // end while

			if(found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;

				if(last == current)			//node to be deleted was
											//the last node
					last = trailCurrent;	//update the value of last
				delete current;				//delete the node from the list
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
		} //end else
	} //end else
} //end deleteNode

template<class Type>
linkedListType<Type>::~linkedListType() // destructor
{
	nodeType<Type> *temp;

	while(first != NULL)  //while there are nodes left in the list
	{
		temp = first;         //set temp point to the current node
		first = first->link;  //advance first to the next node
		delete temp;          //deallocate memory occupied by temp
	}//end while

	last = NULL; //initialize last to NULL; first is already null
}//end destructor


	//copy constructor
template<class Type>
linkedListType<Type>::linkedListType(
            				const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list

    if(otherList.first == NULL) //otherList is empty
    {
		first = NULL;
		last = NULL;
	}
	else
	{
		current = otherList.first;  //current points to the
									//list to be copied

			//copy the first node
		first = new nodeType<Type>;  //create the node
		first->info = current->info; //copy the info
		first->link = NULL;  	     //set the link field of
									 //the node to NULL
		last = first;    		     //make last point to the
									 //first node
		current = current->link;     //make current point to the
									 //next node

			//copy the remaining list
		while(current != NULL)
		{
			newNode = new nodeType<Type>;	//create a node
			newNode->info = current->info;	//copy the info
			newNode->link = NULL;   	    //set the link of
											//newNode to NULL
			last->link = newNode; 		//attach newNode after last
			last = newNode;   			//make last point to
										//the actual last node
			current = current->link;   //make current point to
										//the next node
		}//end while
	}//end else
}//end copy constructor


	//overload the assignment operator
template<class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(
   	 	 					const linkedListType<Type>& otherList)
{
	nodeType<Type> *newNode; //pointer to create a node
	nodeType<Type> *current; //pointer to traverse the list.

	if(this != &otherList) //avoid self-copy
	{

		if(first != NULL)  //if the list is not empty, destroy the list
		{
			destroyList();
		}

		if(otherList.first == NULL) //otherList is empty
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			current = otherList.first;	//current points to the
										//list to be copied

				//copy the first element
			first = new nodeType<Type>;		//create the node
   			first->info = current->info;	//copy the info
   			first->link = NULL;  			//set the link field of
											//the node to NULL
			last = first;            //make last point to the first node
			current = current->link; //make current point to the next
  		  							 //node of the list being copied

				//copy the remaining list
			while(current != NULL)
			{
				newNode = new nodeType<Type>;
				newNode->info = current->info;
				newNode->link = NULL;
				last->link = newNode;
				last = newNode;
				current = current->link;
			}//end while
		}//end else
	}//end else

   return *this;
}
#endif
