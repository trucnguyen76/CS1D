/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #6: Priority Queue
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 3/3/15
 *************************************************************************/
#ifndef ORDEREDLINKLIST_H
#define ORDEREDLINKLIST_H

#include "linklist.h"
using namespace std;

template <class Type>
class OrderedLinkList: public LinkList<Type>
{
public:
    /*****************************************************************************
    * OrderedLinkList()
    * 	This constructor will create an empty linked list
    *****************************************************************************/
    OrderedLinkList();

    /*****************************************************************************
    * OrderedLinkList()
    * 	This copy constructor will create a list from another list
    *****************************************************************************/
    OrderedLinkList(const OrderedLinkList<Type> &otherList);

    /*****************************************************************************
    * ~OrderedLinkList()
    * 	This destructor will destroy the LinkedList object
    *****************************************************************************/
    ~OrderedLinkList();

    /*****************************************************************************
    * insert()
    * 	This method will insert the newItem to the the specified position of the
    * 	 list and push back the rest of the list
    * 	-> Return nothing
    * 	POST: The item being added to the list
    *****************************************************************************/
    void insert(const Type& newItem);	//IN - The newItem being added to the list
    /*****************************************************************************
    * deleteItem()
    * 	This method will search and delete the item from the list
    * 	-> Return nothing
    * 	POST:	the item is removed from the list if it is found
    * 			the list is the same if the item is not found
    *****************************************************************************/
    void deleteItem(const Type& deleteItem);//OUT - The item being deleted

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
     * retrieveFirst
     *		This method will return the first node in the list
     *		-> RETURN the first element
     ************************************************************************/
    Type& retrieveFirst()	;

    /*************************************************************************
     * retrieveLast
     *		This method will return the last node in the list
     *		-> RETURN the last element
     ************************************************************************/
    Type& retrieveLast()	;

    /*************************************************************************
     * retrieve
     *		This method will return the item in the list at the specific position
     *		-> RETURN the element
     ************************************************************************/
    Type& retrieve(int index) ;		//IN - The index of that element

    /*************************************************************************
     * size
     *		This method returns the size of the queue
     *		-> RETURN the size of the queue as an integer
     ************************************************************************/
    int  getSize()							const;

    class ItemAlreadyExists{};//Class to handle exception if item already exists

    void print();

protected:
    /*****************************************************************************
    * insertFirst()
    * 	This method will insert the newItem to the head of the list
    * 	-> Return nothing
    * 	POST: The item being added to the list and become the first item
    *****************************************************************************/
    void insertFirst(const Type& newItem);	//IN - The newItem being added

    /*****************************************************************************
    * insertLast()
    * 	This method will insert the newItem to the tail of the list
    * 	-> Return nothing
    * 	POST: The item being added to the list and become the last item
    *****************************************************************************/
    void insertLast(const Type& newItem);	//IN - The newItem being added

    /*****************************************************************************
    * insert()
    * 	This method will insert the newItem to the the specified position of the
    * 	 list and push back the rest of the list
    * 	-> Return nothing
    * 	POST: The item being added to the list
    *****************************************************************************/
    void insert(const Type& newItem,	//IN - The newItem being added to the list
                        int	index);		//IN - The index where to insert the item

    /*****************************************************************************
    * deleteItem()
    * 	This method will delete the node at the specified position of the list
    * 	-> Return the deleteItem through the parameter
    * 	POST: The item being deleted to the list
    *****************************************************************************/
    void deleteItem(Type& deleteItem,	//OUT - The item being deleted
                        int	index);		//IN - The index where to insert the item

    /*****************************************************************************
    * deleteFirst()
    * 	This method will remove the first item of the list
    * 	-> Return the deleteItem through the parameter
    * 	POST:	the first item is removed from the list
    *****************************************************************************/
    void deleteFirst(Type& deleteItem);	//OUT - The item being deleted

    /*****************************************************************************
    * deleteLast()
    * 	This method will remove the last item of the list
    * 	-> Return the deleteItem through the parameter
    * 	POST:	the last item is removed from the list
    *****************************************************************************/
    void deleteLast(Type& deleteItem);	//OUT - The item being deleted

    /*************************************************************************
     * search
     *		This method will search for the searchItem in the list.
     *		-> RETURN nothing
     ************************************************************************/
    Node<Type>* search(const Type& searchItem)	const;
                                        //IN - The item being searched for
};

template <class Type>
OrderedLinkList<Type>::OrderedLinkList() : LinkList<Type>::LinkList(){}

template <class Type>
OrderedLinkList<Type>::OrderedLinkList(const OrderedLinkList<Type> &otherList)
            : LinkList<Type>::LinkList(otherList) {}

template <class Type>
OrderedLinkList<Type>::~OrderedLinkList()
{
    destroyList();
}

template <class Type>
void OrderedLinkList<Type>::insertFirst(const Type& newItem)
                //IN - The newItem being added to the list

{
   LinkList<Type>::insertFirst(newItem);
}

template <class Type>
void OrderedLinkList<Type>::insertLast(const Type& newItem)
                //IN - The newItem being added to the list

{
    LinkList<Type>::insertLast(newItem);
}

template <class Type>
void OrderedLinkList<Type>::insert(const Type& newItem,
                                         int	index)

{
    LinkList<Type>::insert(newItem, index);
}

template <class Type>
void OrderedLinkList<Type>::insert(const Type& newItem)
{
    bool 	 	found;			//CALC	- Indicates whether the item is found
    Node<Type> 	*srchPtr;		//OUT 	- Pointer points to the node being searched
    Node<Type>	*nodePtr;		//CALC  - Auxiliary Pointer holds new item

    //INITIALIZATION
    srchPtr = LinkList<Type>::first;
    found = false;
    //If the list is emtpy, then add to the head
    if(isEmpty())
    {
        insertFirst(newItem);
    }
    else
    {
    	//If the list has only 1 item
        if(srchPtr->next == NULL && !(srchPtr->object == newItem))
        {
        	//If the new item greater than the existing object
        	if(newItem > srchPtr->object)
        	{
        		insertLast(newItem);
        	}
        	else
        	{
        		insertFirst(newItem);
        	}
        }
        else
        {
            //Find the position to add node & check if the node already exists
			//If don't want duplicate, add : && !(srchPtr->object == newItem)
            while (srchPtr != NULL && !found)
            {
                //Find the person who will stands next to the one being added
            	//If do not want duplicate -> > instead of >=
                if(srchPtr->object >= newItem)
                {
                    found = true;
                }
                //Move to the next object if the greater value isn't found
                else
                {
                    srchPtr= srchPtr->next;
                }
            }
            //Insert middle
            if(found)
            {
            	if(srchPtr == LinkList<Type>::first)
            	{
            		insertFirst(newItem);
            	}
            	//If don't want duplicate, remove this portion of else if
            	else if(srchPtr-> object == newItem)
            	{
					nodePtr = new Node<Type>;
					nodePtr->object = newItem;

            		nodePtr ->prev = srchPtr;
            		nodePtr->next  = srchPtr->next;

            		srchPtr->next->prev = nodePtr;
            		srchPtr->next		= nodePtr;

	                LinkList<Type>::size++;

            	}
            	else
            	{

					nodePtr = new Node<Type>;
					nodePtr->object = newItem;

					//Link the PREVIOUS and NEXT pointer of the node being added
					nodePtr -> prev 	= srchPtr -> prev;
					nodePtr -> next 	= srchPtr;

					//Link the list to the node being added
					srchPtr -> prev -> next =  nodePtr;
					srchPtr-> prev 			= nodePtr;

	                LinkList<Type>::size++;
            	}
            }
            //There's no item > new item -> insertLast
            else if(srchPtr == NULL)
            {
            	insertLast(newItem);
            }
//            else if((srchPtr->object == newItem))
//            {
//            	cout << "Item already exists. Cannot insert\n";
//
//            }
        }
    }
    srchPtr = NULL;
    nodePtr = NULL;
}

template <class Type>
void OrderedLinkList <Type> :: destroyList()
{
    LinkList<Type>::destroyList();
}

template <class Type>
void OrderedLinkList<Type>:: deleteItem(const Type& deleteItem)
            //IN - The item being deleted from the list
{
    LinkList<Type>::deleteItem(deleteItem);
}

template <class Type>
void OrderedLinkList<Type>::deleteItem(Type& deleteItem,
                                             int	index)
{
    LinkList<Type>::deleteItem(deleteItem, index);

}

template <class Type>
void OrderedLinkList<Type>:: deleteFirst(Type& deleteItem)
{
    LinkList<Type>::deleteFirst(deleteItem);
}

template <class Type>
void OrderedLinkList<Type>:: deleteLast(Type& deleteItem)
{
    LinkList<Type>::delelteLast(deleteItem);
}

template <class Type>
bool OrderedLinkList <Type> :: isEmpty()	const
{
    return LinkList<Type>::isEmpty();

}

template <class Type>
int OrderedLinkList <Type> :: getSize()     const
{
    return LinkList<Type>::getSize();
}

template <class Type>
Node<Type>* OrderedLinkList<Type>::search (const Type& searchItem)	const

{
    return LinkList<Type>::search(searchItem);
}
template <class Type>
Type& OrderedLinkList<Type>::retrieveFirst()


{
    return LinkList<Type>::retrieveFirst();
}

template <class Type>
Type& OrderedLinkList<Type>::retrieveLast()

{
    return LinkList<Type>::retrieveLast();
}

template <class Type>
Type& OrderedLinkList<Type>::retrieve(int index)
{
    return LinkList<Type>::retrieve(index);
}

template <class Type>
void OrderedLinkList<Type>::print()
{
	int index = 0;
	while(index < LinkList<Type>::size)
	{
		(retrieve(index)).print();

		index++;
	}
	cout << endl;
}

#endif // ORDEREDLINKLIST_H
