/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT#11: Directed Graph
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 4/2/15
 *************************************************************************/
#include <iostream>
#include "graph.h"

using namespace std;

string PrintHeader(	string  programmer,	//IN 		- programmer(s)'s name
                    char 	asType, 	//IN 		- assignment type
                    string 	asName,		//IN & OUT 	- assignment name
                    int 	asNum);		//IN & OUT 	- assignment number
int main()
{    
    Graph graph;

    cout << PrintHeader("Elva Nguyen", 'a', "Directed Graph", 11);

    graph.insertVertex("Los Angeles");
    graph.insertVertex("San Francisco");
    graph.insertVertex("Seattle");
    graph.insertVertex("Denver");
    graph.insertVertex("Chicago");
    graph.insertVertex("Kansas City");
    graph.insertVertex("Dallas");
    graph.insertVertex("Houston");
    graph.insertVertex("Miami");
    graph.insertVertex("Atlanta");
    graph.insertVertex("New York");
    graph.insertVertex("Boston");

    graph.insertEdge(1, 0, 381);
    graph.insertEdge(0, 3, 1015);
    graph.insertEdge(5, 0, 1663);
    graph.insertEdge(6, 0, 1435);


    graph.insertEdge(2, 1, 807);
    graph.insertEdge(3, 1, 1267);


    graph.insertEdge(2, 3, 1331);
    graph.insertEdge(4, 2, 2097);

    graph.insertEdge(3, 4, 1003);
    graph.insertEdge(5, 3, 599);

    //Chicago
    graph.insertEdge(5, 4, 533);
    graph.insertEdge(10, 4, 787);
    graph.insertEdge(4, 11, 983);

    //Kansas
    graph.insertEdge(6, 5, 496);
    graph.insertEdge(5, 9, 864);
    graph.insertEdge(5, 10, 1260);

    //Dallas
    graph.insertEdge(7, 6, 239);
    graph.insertEdge(6, 9, 781);

    //Houston
    graph.insertEdge(8, 7, 1187);
    graph.insertEdge(7, 9, 810);

    //Miami
    graph.insertEdge(9, 8, 661);

    //Atlanta
    graph.insertEdge(10, 9, 888);

    //New York
    graph.insertEdge(11, 10, 214);

    graph.depthFirstTraversal(11);

    cout << endl << endl;

    graph.breathFirstTraversal(11);
}

