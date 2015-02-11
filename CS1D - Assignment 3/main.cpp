/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #3: Stack and Deque
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 2/10/15
 *************************************************************************/
#include "header.h"

int main()
{
	StackVector<string> 	vector1;
	StackVector<double> 	vector2;
	StackVector<int> 		vector3;

	linkedStackType<string> stack1;
	linkedStackType<double> stack2;
	linkedStackType<int> 	stack3;
	linkedStackType<string>	expressions;

	LinkedDeque<string>		deque1;
	LinkedDeque<double>		deque2;
	LinkedDeque<int>		deque3;

	int index;
	string str;

	cout << PrintHeader("Elva Nguyen", 'a', "Stack and Deque", 3);

	cout << "Part 1: Stack using vector\n\n";
	vector1.push("Paula");
	vector1.push("JoAnn");
	vector1.push("Jack");
	vector1.push("Mark");
	vector1.push("Paul");
	vector1.push("Eric");

	cout << "Stack 1 is: \n";
	vector1.print();
	cout << endl;

	vector2.push(2788.123);
	vector2.push(243.76);
	vector2.push(8445.5612);
	vector2.push(19833.121);
	vector2.push(12.4);

	cout << "Stack 2 is: \n";
	vector2.print();
	cout << endl;

	vector3.push(98);
	vector3.push(88);
	vector3.push(88);
	vector3.push(123);
	vector3.push(8445);
	vector3.push(9833);
	vector3.push(12);
	vector3.push(354);

	cout << "Stack 3 is: \n";
	vector3.print();
	cout << endl;

	cout << setfill('*');
	cout << setw(75) << '*' << endl;
	cout << "Part 2: Stack using Singly Linked List\n\n";
	stack1.push("Paula");
	stack1.push("JoAnn");
	stack1.push("Jack");
	stack1.push("Mark");
	stack1.push("Paul");
	stack1.push("Eric");

	cout << "Stack 1 is: \n";
	stack1.print();
	cout << endl;

	stack2.push(2788.123);
	stack2.push(243.76);
	stack2.push(8445.5612);
	stack2.push(19833.121);
	stack2.push(12.4);

	cout << "Stack 2 is: \n";
	stack2.print();
	cout << endl;

	stack3.push(98);
	stack3.push(88);
	stack3.push(88);
	stack3.push(123);
	stack3.push(8445);
	stack3.push(9833);
	stack3.push(12);
	stack3.push(354);

	cout << "Stack 3 is: \n";
	stack3.print();
	cout << endl;

	cout << setw(75) << '*' << endl;
	cout << "Part 3: Deque Using Link List\n\n";

	deque1.insertFront("Jack");
	deque1.insertFront("Mark");
	deque1.insertFront("Paul");
	deque1.insertFront("Eric");
	deque1.insertBack("JoAnn");
	deque1.insertBack("Paula");

	cout << "deque 1 is: \n";
	deque1.print();
	cout << endl;

	deque2.insertBack(2788.123);
	deque2.insertFront(243.76);
	deque2.insertFront(8445.5612);
	deque2.insertFront(19833.121);
	deque2.insertFront(12.4);

	cout << "deque 2 is: \n";
	deque2.print();
	cout << endl;

	deque3.insertBack(354);
	deque3.insertBack(12);
	deque3.insertBack(9833);
	deque3.insertBack(8445);
	deque3.insertBack(123);
	deque3.insertBack(88);
	deque3.insertBack(88);
	deque3.insertBack(98);

	cout << "deque 3 is: \n";
	deque3.print();
	cout << endl;

	cout << setw(75) << '*' << endl;
	cout << "Part 4: Parentheses Algorithm\n\n";

	index = 0;

	expressions.push("{2x+3}{7x+8}");
	expressions.push("{2x + 5) (6x+4)}");
	expressions.push("[(8x+5) - 4x[9x+3]]");
	expressions.push("{(8x+5) - 5x[9x+3]})");
	expressions.push("(((8x+5) - x[9x+3])))");
	expressions.push("{(8x+5) - 9x[9x+3]]");

	while(index < 6)
	{
		expressions.pop(str);

		cout << str
			 << (ParenthesesMatching(str.c_str(), str.size())? " ": " does not ")
			 << "match\n";
		if(ParenthesesMatching(str.c_str(), str.size()))
		{
			cout << str << " = " << EvaluateExpression(str);
			cout << endl;
		}
		index++;
	}

//	string str1;
//	str1 = "[(8x+5) - 4x[9x+3]]";
//	cout << str1 ;
//	cin.ignore(1000, '\n');
//	cout << EvaluateExpression(str1);
	return 0;
}




