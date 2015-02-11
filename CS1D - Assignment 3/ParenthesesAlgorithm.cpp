/**************************************************************************
 * AUTHOR     	: Elva Nguyen
 * STUDENT ID 	: 366160
 * ASSIGNMENT #3: Stack and Deque
 * CLASS      	: Computer Science 1D
 * SECTION    	: T - Th 5:30 - 9:20pm
 * DUE DATE   	: 2/10/15
 *************************************************************************/
#include <iomanip>
#include "linkedStack.h"

using namespace std;

bool ParenthesesMatching(const char array[],	//IN  - The array of character
								int arraySize)	//OUT - The size of the array
{
	int  index;
	char symbol;

	linkedStackType<char> stack;

	for(index = 0; index < arraySize; index++)
	{
		if(array[index] == '{' || array[index] == '[' || array[index] == '(')
		{
			stack.push(array[index]);
		}
		else if(array[index] == '}' || array[index] == ']' || array[index] == ')')
		{
			if(stack.isEmptyStack())
			{
				//There is nothing to match with
				return false;
			}
			symbol = '?';
			stack.pop(symbol);

			if(((array[index] == '}' && symbol != '{') ||
			   (array[index] == ']'  && symbol != '[') ||
			   (array[index] == ')'  && symbol != '(')))
			{
				//Wrong type
				return false;
			}
		}
	}
	//If stack is empty -> everything matches; else some symbols never matched
	return stack.isEmptyStack();
}




