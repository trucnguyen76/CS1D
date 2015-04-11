/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT#11: Directed Graph
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 4/2/15
 *************************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

struct Vertex
{
    string  name;       //Vertex name
    int     number;     //Vertex number
};

class Graph
{
    static const int MAX_VERTEX = 12;
    static const int INFINITY = 10000;


public:
    /************************************************************************
     * Graph()
     *  This constructor will initialize the variables
     ***********************************************************************/
    Graph();

    /************************************************************************
     * Graph()
     *  This destructor will destroy all the variables
     ***********************************************************************/
    ~Graph();

    /************************************************************************
     * insertEdge()
     *  This method will insert an edge between origin vertex and destination
     *      vertex with the given weight
     *  -> RETURN nothing
     *  POST: put the edge's weight into the adjacencyMatrix
     * **If undirected -> add to 2 spots
     *   If difrected -> add to 1 spot
     ***********************************************************************/
    void insertEdge(int originNumber, 		//IN - The number of origin vertex
    				int destinationNumber, 	//IN - The number of dest vertex
    				double weight);			//IN - The weight of the edge

    /************************************************************************
     * insertVertex()
     *  This method will insert a vertex name vName
     *  -> RETURN nothing
     *  POST: create new vertex and add that new vertex to vertex list
     ***********************************************************************/
    void insertVertex(string vName);	//IN - The Vertex name

    /************************************************************************
     * depthFirstTraversal()
     *  This method will perform a depth first traversal and print the list in
     *      order
     *  -> RETURN nothing
     ***********************************************************************/
    void depthFirstTraversal(int startVertex);	//IN - Start vertex number

    /************************************************************************
     * breathFirstTraversal()
     *  This method will perform a breath first traversal and print the list in
     *      order
     *  -> RETURN nothing
     ***********************************************************************/
    void breathFirstTraversal(int startVertex);	//IN - Start vertex number

    /************************************************************************
     * printMatrix()
     *  This method will print the graph adjacencyList
     *  -> RETURN nothing
     ***********************************************************************/
    void printMatrix();

private:
    vector <Vertex>          vertexList;			//The Vertex list
    double adjacencyMatrix[MAX_VERTEX][MAX_VERTEX];	//Adjacency Matrix for edge
    int totalVertex;								//Total num of vertices
//    int count = 0;

protected:
    /************************************************************************
     * printMatrix()
     *  This method will print the matrix in the parameter
     *  -> RETURN nothing
     ***********************************************************************/
    void depthFirst(int startVertex, 				//IN - Start Vertex Num
    				double matrix[][MAX_VERTEX], 	//IN & OUT - weight Matrix
    				vector<int>& visitedVertices);	//OUT - visited vertex list

    /************************************************************************
     * printMatrix()
     *  This method will print the matrix in the parameter
     *  -> RETURN nothing
     ***********************************************************************/
    void breathFirst(int startVertex, 				//IN - Start Vertex Num
    				double matrix[][MAX_VERTEX], 	//IN & OUT - weight Matrix
    				vector<int>& visitedVertices, 	//OUT - visited vertex list
    				int& currentVertexIndex);		//IN & OUT - The index of
    												//	the vertex whose
    												// children vertices are
    												// the ones that we r visit
    												// in visitedVertices list

    /************************************************************************
     * printMatrix()
     *  This method will print the matrix in the parameter
     *  -> RETURN nothing
     ***********************************************************************/
    void printMatrix(double matrix[][MAX_VERTEX]);	//IN - weight Matrix
};

Graph::Graph()
{
    totalVertex = 0;
    int row, col;
//    vertexList.reserve(10);

    for(row = 0; row < MAX_VERTEX; row++)
    {
        for(col = 0; col < MAX_VERTEX; col++)
        {
            adjacencyMatrix[row][col] = INFINITY;
        }
    }
}

Graph::~Graph(){}

void Graph::insertEdge(int originNumber, int destinationNumber, double weight)
{
    adjacencyMatrix[originNumber][destinationNumber] = weight;
//    adjacencyMatrix[destinationNumber][originNumber] = weight;
}

void Graph::insertVertex(string vName)
{
    Vertex newVertex;
    newVertex.name = vName;
    newVertex.number = totalVertex;
//    adjacencyMatrix[totalVertex][totalVertex] = 0;
    totalVertex++;
    vertexList.push_back(newVertex);
}

void Graph::depthFirstTraversal(int startVertex)
{
    int col, row;

    double matrix[MAX_VERTEX][MAX_VERTEX];

    for(row = 0; row < MAX_VERTEX; row++)
    {
        for(col = 0; col < MAX_VERTEX; col++)
        {
            matrix[row][col] = adjacencyMatrix[row][col];
        }
    }

    vector<int> visitedVertices;
    visitedVertices.push_back(startVertex);

    depthFirst(startVertex, matrix, visitedVertices);

//    for(int index = 0; index < visitedVertices.size(); index++)
//    {
//        cout << visitedVertices[index];
//        cout << endl;
//    }

    cout << "Depth First Traversal\n";
    //Print out the visited node
    for(int index = 0; index < (int)visitedVertices.size(); index++)
    {
        cout << vertexList[visitedVertices[index]].name << endl;
    }
}

void Graph::breathFirstTraversal(int startVertex)
{
    int col, row;
    int currentVertexIndex;
    vector<int> visitedVertices;

    double matrix[MAX_VERTEX][MAX_VERTEX];

    //Copy the adjacency matrix
    for(row = 0; row < MAX_VERTEX; row++)
    {
        for(col = 0; col < MAX_VERTEX; col++)
        {
            matrix[row][col] = adjacencyMatrix[row][col];
        }
    }

    currentVertexIndex = 0;
    visitedVertices.push_back(startVertex);

    breathFirst(startVertex, matrix, visitedVertices, currentVertexIndex);

//    for(int index = 0; index < visitedVertices.size(); index++)
//    {
//        cout << visitedVertices[index];
//        cout << endl;
//    }

    cout << "Breath First Traversal\n";
    //Print out the visited node
    for(int index = 0; index < (int)visitedVertices.size(); index++)
    {
        cout << vertexList[visitedVertices[index]].name << endl;
    }
}

void Graph::depthFirst(int startVertex, double matrix[][MAX_VERTEX], vector<int>& visitedVertices)
{
//    count++;
//    cout << "Start count: "<< count << endl;
    double lowestWeight;
    int lowestWeightIndex = startVertex;
    bool visitedAll = false;

//    cout << "Start Vertex is: " << startVertex << endl;
//    cout << "Print Matrix:\n";
//    printMatrix(matrix);
//    cin.ignore(1000, '\n');

    //Make visited vertex unavailable by blank out that column
    for(int index = 0; index < MAX_VERTEX; index++)
    {
        matrix[index][startVertex] = INFINITY;
    }


    //Keep checking adjacent edge until all adjacent edges is visited all
    while(!visitedAll)
    {
        lowestWeight = INFINITY;
         //Find the one that is the closest
        for(int index = 0; index < MAX_VERTEX; index++)
        {
            if(matrix[startVertex][index] < lowestWeight)
            {
                lowestWeight = matrix[startVertex][index];
                lowestWeightIndex = index;
            }
        }
//        cout << "End finding the closest\n";

        //If found a closest adjacent vertex -> call on itself, otherwise ->stop
        if(lowestWeight != INFINITY)
        {
            //Clear the path that we will take
            matrix[startVertex][lowestWeightIndex] = INFINITY;

            visitedVertices.push_back(lowestWeightIndex);

//            cout << "Lowest weight is: "<< lowestWeight << endl;
            depthFirst(lowestWeightIndex, matrix, visitedVertices);
//            cout << "Return to count: " << count << endl;
        }
        else
        {
//            cout << "In else\n";
//            cout << "Start vertex is: " << startVertex << endl;
//            cout << "Visited All\n";
            visitedAll = true;
        }
    }//End while

//    cout << "Return the stack\n";
}

void Graph::breathFirst(int startVertex, double matrix[][MAX_VERTEX],
						vector<int>& visitedVertices, int& currentVertexIndex)
{
	//    count++;
	//    cout << "Start count: "<< count << endl;
	    double lowestWeight;
	    int lowestWeightIndex = startVertex;
//	    bool visitedAll = false;

	//    cout << "Start Vertex is: " << startVertex << endl;
	//    cout << "Print Matrix:\n";
	//    printMatrix(matrix);
	//    cin.ignore(1000, '\n');



		while(visitedVertices.size() != vertexList.size())
		{
		    do
		    {
//			    cout << "Start Vertex is: " << startVertex << endl;
//			    cout << "Print Matrix:\n";
//			    printMatrix(matrix);
//			    cin.ignore(1000, '\n');

		    	lowestWeight = INFINITY;
				startVertex = visitedVertices[currentVertexIndex];

	    	    //Make visited vertex unavailable by blank out that column
	    	    for(int index = 0; index < MAX_VERTEX; index++)
	    	    {
	    	        matrix[index][startVertex] = INFINITY;
	    	    }

		         //Find the one that is the closest
		        for(int index = 0; index < MAX_VERTEX; index++)
		        {
		            if(matrix[startVertex][index] < lowestWeight)
		            {
		                lowestWeight = matrix[startVertex][index];
		                lowestWeightIndex = index;
		            }
		        }

		        if(lowestWeight != INFINITY)
		        {
//cout << "If not infinity\n";
//cout << "LowestWeightIndex is: " << lowestWeightIndex << endl;
		        	visitedVertices.push_back(lowestWeightIndex);

		        	//Clear the path just take

		        	matrix[startVertex][lowestWeightIndex] = INFINITY;
		        }

//		        cout << "VistedVertices are: " << endl;
//		        for(int index = 0; index < visitedVertices.size(); index++)
//		        {
//		        	cout << visitedVertices[index] << '\t';
//		        }
//		        cout << endl;

//		        cout << "End 1 iteration of do while\n";

		    }while(lowestWeight != INFINITY);

//		    cout << "End 1 iteration of WHILE\n";

		    currentVertexIndex++;
		}
}

void Graph::printMatrix()
{
    int col, row;

    for(row = 0; row < MAX_VERTEX; row++)
    {
        for(col = 0; col < MAX_VERTEX; col++)
        {
            cout << setw(6) << adjacencyMatrix[row][col];
        }

        cout << endl;
    }
}

void Graph::printMatrix(double matrix[][MAX_VERTEX])
{
    int col, row;

    cout << setw(6) << "";

    for(col = 0; col < MAX_VERTEX; col++)
    {
        cout << setw(6) << col;
    }
    cout << endl;



    for(row = 0; row < MAX_VERTEX; row++)
    {
        cout << setw(6) << row;

        for(col = 0; col < MAX_VERTEX; col++)
        {
            cout << setw(6) << matrix[row][col];
        }

        cout << endl;
    }
}






#endif // GRAPH_H
