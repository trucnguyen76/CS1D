/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #3: Stack and Deque
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 2/10/15
 *************************************************************************/
#ifndef LINKLIST_H
#define LINKLIST_H

#include <iomanip>
#include <iostream>
using namespace std;

template <class Type>
struct Node
{
    Node<Type> *prev;
    Type object;
    Node<Type> *next;
};

template <class Type>
class LinkList
{
public:

    /*****************************************************************************
    * LinkList()
    * 	This constructor will create an empty linked list
    *****************************************************************************/
    LinkList();

    /*****************************************************************************
    * LinkList()
    * 	This copy constructor will create a list from another list
    *****************************************************************************/
    LinkList(const LinkList &otherList);	//IN - The list being copied from

    /*****************************************************************************
    * ~LinkList()
    * 	This destructor will destroy the LinkedList object
    *****************************************************************************/
    ~LinkList();

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
    * 	This method will search and delete the item from the list
    * 	-> Return nothing
    * 	POST:	the item is removed from the list if it is found
    * 			the list is the same if the item is not found
    *****************************************************************************/
    void deleteItem(const Type& deleteItem);//OUT - The item being deleted


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
     *		-> RETURN the first element thru the parameter
     ************************************************************************/
    void retrieveFirst(Type& object);	//OUT - The first object

    /*************************************************************************
     * retrieveLast
     *		This method will return the last node in the list
     *		-> RETURN the last element thru the parameter
     ************************************************************************/
    void retrieveLast(Type& object);	//OUT - The last object

    /*************************************************************************
     * retrieve
     *		This method will return the item in the list at the specific position
     *		-> RETURN the element thru the parameter
     ************************************************************************/
    void retrieve(int index,			//IN  - The index of that element
    			  Type& object);		//OUT - The object at the index

    /*************************************************************************
     * getSize
     *		This method returns the size of the queue
     *		-> RETURN the size of the queue as an integer
     ************************************************************************/
    int  getSize()							const;

//    class Empty{};          //Class to handle exception when the list is empty
//    class InvalidIndex{};   //Class to handle exception if invalid index

protected:
    /*************************************************************************
     * search
     *		This method will search for the searchItem in the list.
     *		-> RETURN where the search item is or null if !found
     ************************************************************************/
    Node<Type>* search(const Type& searchItem)	const;
                                        //IN - The item being searched for
    /*************************************************************************
     * getFirstPtr()
     *		This method will return the pointer points to the first node
     *		-> RETURN the pointer points to the first node
     ************************************************************************/
    Node<Type>* getFirstPtr()                   const;

    /*************************************************************************
     * getLastPtr()
     *		This method will return the pointer points to the last node
     *		-> RETURN the pointer points to the last node
     ************************************************************************/
    Node<Type>* getLastPtr()                    const;

    /*************************************************************************
     * setSize
     *		This method set the size of the link list
     *		-> RETURN nothing
     ************************************************************************/
    void  setSize(int newSize);

private:
    int	size;			//The size of the linked list
    Node<Type> *first;	//Pointer points to the first node of the list
    Node<Type> *last;	//Pointer points to the last node of the list

};

template <class Type>
LinkList<Type>::LinkList()
{
    first = NULL;
    last = NULL;
    size = 0;
}

template <class Type>
LinkList<Type>::LinkList(const LinkList &otherList)
{
    first = NULL;
    last = NULL;
    size = 0;

    if(!otherList.isEmpty())
    {
        Node<Type>	*addPnt;	//CALC - pointer points to the item being added

        addPnt = otherList.first;

        while(addPnt != NULL)
        {
            insertLast(addPnt->object);
            addPnt = addPnt->next;
        }
    }
}

template <class Type>
LinkList<Type>::~LinkList()
{
    destroyList();
}

template <class Type>
void LinkList<Type>::insertFirst(const Type& newItem)
{
    Node<Type>	  *nodePnt;	//CALC - auxiliary pointer holds the new item

    //INITIALIZATION
    // creates new struct of type Node
    nodePnt = new Node<Type>;

    nodePnt->object 	= newItem;
    nodePnt->next		= NULL;
    nodePnt->prev		= NULL;

    if(isEmpty())
    {
        first	       	= nodePnt;
        last         	= nodePnt;
        nodePnt       	= NULL;
    }
    else
    {
        nodePnt->next 	= first;
        first->prev		= nodePnt;

        first			= nodePnt;
        nodePnt 		= NULL;
    }


    size++;

    delete nodePnt;
    nodePnt = NULL;
}

template <class Type>
void LinkList<Type>::insertLast(const Type& newItem)
                                        //IN - The newItem being added to the list

{
    Node<Type> *nodePnt;	//CALC - auxiliary pointer holds the new item

    //INITIALIZATION
    // creates new struct of type Node
    nodePnt = new Node<Type>;

    nodePnt->object 	= newItem;
    nodePnt->next		= NULL;
    nodePnt->prev		= NULL;

    /***********************************************************************
     * Check whether the list is empty or not. If the list is empty then
     * 	the program will add the first node to the front, otherwise, it will
     * 	add the new node to the rear of the link
     **********************************************************************/
    if(isEmpty())
    {
        insertFirst(newItem);
    }
    else
    {
        nodePnt-> prev	= last;
        last->next		= nodePnt;

        last = last->next;
        nodePnt			= NULL;
        size++;
    }

    delete nodePnt;
    nodePnt = NULL;
}

template <class Type>
void LinkList<Type>::insert(const Type& newItem, //IN - The newItem being added
                                    int	index)//IN - The position to add the item

{
    Node<Type>	*nodePnt;	//CALC - auxiliary pointer holds the new item
    Node<Type>	*srchPnt;	//CALC - search pointer
    int			counter;	//CALC - counter to the position being inserted

    //INITIALIZATION
    srchPnt = first;
    counter = 0;

    // creates new struct of type Node
    nodePnt = new Node<Type>;

    nodePnt->object 	= newItem;
    nodePnt->next		= NULL;

    if(index == 0)
    {
        insertFirst(newItem);
    }
    else if(index == size)
    {
        insertLast(newItem);
    }
    else if(index < size && index > 0)
    {
        //Iterate to the position where to add the item
        while(counter < index)
        {
            srchPnt = srchPnt->next;
            counter++;
        }

        nodePnt->next = srchPnt;
        nodePnt->prev = srchPnt->prev;

        srchPnt->prev->next = nodePnt;
        srchPnt->prev = nodePnt;

        size++;
    }

    srchPnt = NULL;
    nodePnt = NULL;
}

template <class Type>
void LinkList <Type> :: destroyList()
{
    Node<Type> *nodePnt;	//CALC - The node pointer points to the item removed

    while(!isEmpty())
    {
        nodePnt = first;
        first = first->next;
        size--;
        delete nodePnt;
    }

    last = NULL;
    nodePnt = NULL;

}

template <class Type>
void LinkList<Type>:: deleteItem(const Type& deleteItem)
                                    //IN - The item being deleted from the list
{
    Node<Type> *searchPtr;	//CALC 	- Pointer points to the node being searched
    Type		item;		//CALC  - Auxiliary item holder

    //Search for the item being removed in the list
    searchPtr = search(deleteItem);

    /*If the item is found, remove that item out of the list, otherwise
        notify the user that the item is not in the list to be removed */
    if(searchPtr != NULL)
    {
        /******************************************************************
         * If the item is the first in the list, have the previous pointer
         * 	of the item next in the list points to NULL and have the head
         * 	points to that next node
         *****************************************************************/
        if(searchPtr == first)
        {
            deleteFirst(item);
        }

        /*If that item is at the end of the list, have the next pointer of
            the item previous points to NULL (become the rear of the list)*/
        else if(searchPtr->next == NULL)
        {
            searchPtr->prev->next = NULL;
        }

        /******************************************************************
         * If the item is in the middle of the list, then have the NEXT
         *  pointer of the previous item points to the item next to the
         *  item being removed, then reassign the PREVIOUS pointer points
         *  to the next item
         *****************************************************************/
        else
        {
            searchPtr->prev -> next = searchPtr->next;
            searchPtr->next -> prev = searchPtr -> prev;
        }

        //Delete that item and set the pointer to NULL
        delete searchPtr;
        searchPtr = NULL;

        size--;
    }

}

template <class Type>
void LinkList<Type>::deleteItem(Type& deleteItem,
                                int	index)
{
    Node<Type>	*srchPnt;	//CALC - search pointer
    int			counter;	//CALC - counter to the position being inserted

    //INITIALIZATION
    srchPnt = first;
    counter = 0;

    if(index == 0)
    {
        deleteFirst(deleteItem);
    }
    else if(index == size - 1 )
    {
        deleteLast(deleteItem);
    }
    else if(index < size - 1 && index > 0)
    {
        //Iterate to the position where to add the item
        while(counter < index)
        {
            srchPnt = srchPnt->next;
            counter++;
        }

        srchPnt->next->prev = srchPnt->prev;
        srchPnt->prev->next	= srchPnt->next;

        size--;
    }
    else
    {
//        throw InvalidIndex();
//        //Exception
    	cout << "Cannot remove item. Invalid index\n";
    }

    srchPnt = NULL;
}

template <class Type>
void LinkList<Type>:: deleteFirst(Type& deleteItem)
{
    Node<Type>	*deletePnt;	//CALC - The pointer points to the item being deleted

    if(!isEmpty())
    {
        deletePnt = first;
        deleteItem = deletePnt->object;

        //When there is more than 1 node in the list
        if(size > 1)
        {
            first->next->prev = NULL;
            first = first->next;

            delete deletePnt;
            deletePnt = NULL;
        }
        //When there is only one node in the list
        else
        {
            first = NULL;
            last = NULL;
        }

        delete deletePnt;
        deletePnt = NULL;
        size--;
    }
    else
    {
//        throw Empty();
////Exception

    	cout << "The list is empty. Cannot remove item\n";

    }
}

template <class Type>
void LinkList<Type>:: deleteLast(Type& deleteItem)
{
    Node<Type>	*deletePnt;	//CALC - The pointer points to the item being deleted

    if(!isEmpty())
    {
        deletePnt = last;
        deleteItem = deletePnt->object;

        //When there is more than one node in the list
        if(size > 1)
        {
            last->prev->next = NULL;
            last = last->prev;

        }
        //when there is only one node in the list
        else
        {
            first = NULL;
            last = NULL;
        }

        delete deletePnt;
        deletePnt = NULL;
        size--;
    }
    else
    {
//        throw Empty();
//        //Exception

    	cout << "The list is empty. Cannot remove item\n";
    }
}

template <class Type>
bool LinkList <Type> :: isEmpty()	const
{
    return first == NULL;
}

template <class Type>
int LinkList <Type> :: getSize()	const
{
    return size;
}

template <class Type>
Node<Type>* LinkList<Type>::search (const Type& searchItem)	const
{
    bool 	 found;			//CALC	- Indicates whether the item is found
    Node<Type> 	*srchPnt;	//OUT 	- Pointer points to the node being searched

    //INITIALIZATION
    srchPnt = first;
    found = false;

    /*While loop - Keeps looking for the item until the item is found or
        reached the end of the list */
    while (srchPnt != NULL && !found)
    {
        if(srchPnt->object == searchItem)
        {
            found = true;
        }
        else
        {
            srchPnt = srchPnt->next;
        }
    }

    if(!found)
    {
        cout << "Item does not exist";

        srchPnt = NULL;
    }

    return srchPnt;
}

template <class Type>
void LinkList<Type>::retrieveFirst(Type& object)
{
    if(!isEmpty())
    {
        object = first->object;
    }
    else
    {
//        throw Empty();
    	cout << "The list is empty. Cannot retrieve item\n";

    } 
}

template <class Type>
void LinkList<Type>::retrieveLast(Type& object)
{
    if(!isEmpty())
    {
        object = last->object;
    }
    else
    {
//        throw Empty();
    	cout << "The list is empty. Cannot retrieve item\n";
    }
}

template <class Type>
void LinkList<Type>::retrieve(int index,
							Type& object)
{
    Node<Type>	*srchPnt;	//CALC - search pointer
    int			counter;	//CALC - counter to the position of the element

    counter = 0;
    srchPnt = first;

    if(isEmpty())
    {
//        throw Empty();
    	cout << "The list is empty. Cannot retrieve item\n";

    }
    else
    {
        if(index == 0)
        {
            retrieveFirst(object);
        }
        else if(index == (size - 1))
        {
            retrieveLast(object);
        }
        else if(index > 0 && index < size -1)
        {
            while(counter < index)
            {
                srchPnt = srchPnt->next;
                counter++;
            }
            object = srchPnt->object;
        }
        else
        {
//            throw InvalidIndex();

        	cout << "Cannot retrieve item. Invalid Index\n";
        }
    }
}

template <class Type>
Node<Type>*  LinkList<Type>::getFirstPtr()	const
{
    return first;
}

template <class Type>
Node<Type>*  LinkList<Type>::getLastPtr()	const
{
    return last;
}

template <class Type>
void LinkList<Type>::setSize(int newSize)
{
	size = newSize;
}
#endif // LINKLIST_H
