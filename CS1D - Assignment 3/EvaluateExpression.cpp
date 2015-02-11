#include "header.h"

double EvaluateExpression(string str)	//IN - expression as a string
{
	int  index;					//CALC - index of the character in the str
	unsigned int i;				//CALC - index for the for loop

	bool exitLoop;				//CALC - the value to determin
	string numStr;				//CALC - the string of the number
	string str1;				//CALC - Auxiliary string variable
	string str2;				//CALC - Auxiliary string variable
	vector<string>::iterator it;//CALC - iterator to iterate thru the vector
	vector<string> elements;	//CALC - vector of elements of calculations

	int strSize = str.size();
	index = 0;
	exitLoop = false;
	while(!exitLoop && index < strSize)
	{
		//If the character is just an operator -> push to the vector
		if(		str[index] == '*' || str[index] == '/' ||
				str[index] == '+' || str[index] == '-')
		{
		string str3;

		str3 = Convert(str[index]);
			elements.push_back(str3);
		}
		//If the character is an open parentheses
		else if(str[index] == '{' || str[index] == '[' || str[index] == '(')
		{

			if(str[index -1] != '{' && str[index -1] != '[' && str[index -1] != '('
			&& str[index - 1] != '*' && str[index - 1] != '/' &&
			   str[index - 1] != '+' && str[index - 1] != '-' && index != 0)
			{
				elements.push_back("*");
			}

		if(	!(str[index +1] == '{' || str[index +1] == '[' || str[index +1] == '('))
		{
			elements.push_back(
			Convert(EvaluateExpression(str.substr(index + 1, strSize - index - 1))));

			//While loop - Advance index to the closing parentheses so it would not
			//				process the characters that are already processed
			while(!(str[index] == '}' || str[index] == ']' || str[index] == ')' ))
			{
				index++;
			}
		}

		}
		//If the character is a digit -> take all the digit, make it a number
		else if(isdigit(str[index]))
		{

			numStr = str[index];
			index++;
			while(isdigit(str[index]))
			{
				numStr.push_back(str[index]);
				index++;
			}
			elements.push_back(numStr);
			index--;
		}
		//If the character is an 'x'
		else if(str[index] == 'x')
		{

			if(str[index -1] != '{' && str[index -1] != '[' && str[index -1] != '('
			&& str[index] != '*' && str[index] != '/' &&
			   str[index] != '+' && str[index] != '-')
			{
				elements.push_back("*");
			}

			elements.push_back("5");

		}
		//If the character is a close parentheses
		else if(str[index] == '}' || str[index] == ']' || str[index] == ')')
		{

			exitLoop = true;
		}
		index++;

	}//end while

	//For loop - Perform calculations from left to right for * and /
	for(i = 0; i < elements.size(); i++)
	{
		if(elements[i] == "*" || elements[i] == "/")
		{
			str1 = elements[i-1];
			str2 = elements[i + 1];
			if(elements[i] == "*")
			{
				elements[i - 1] = Convert(Convert(str1) * Convert(str2));

			}
			else if(elements[i] == "/")
			{
				elements[i - 1] = Convert(Convert(str1) / Convert(str2));
			}
			//Erase index and index + 1 element
			it = elements.begin();
			for(int j = 0; j < i; j++)
			{
				it++;
			}

			elements.erase(it);

			it = elements.begin();
			for(int j = 0; j < i; j++)
			{
				it++;
			}

			elements.erase(it);

			//Because deleting 2 elements -> have to decrease i also
			i -= 2;
		}

	}
	//For loop - Perform calculations from left to right for + and -
	for(unsigned i = 0; i < elements.size(); i++)
	{
		if(elements[i] == "+" || elements[i] == "-")
		{
			str1 = elements[i-1];
			str2 = elements[i + 1];
			if(elements[i] == "+")
			{
				elements[i - 1] = Convert(Convert(str1) + Convert(str2));
			}
			else if(elements[i] == "-")
			{
				elements[i - 1] = Convert(Convert(str1) - Convert(str2));
			}
			//Erase index and index + 1 element
			it = elements.begin();
			for(int j = 0; j < i; j++)
			{
				it++;
			}

			elements.erase(it);

			it = elements.begin();
			for(int j = 0; j < i; j++)
			{
				it++;
			}

			elements.erase(it);

			//Because deleting 2 elements -> have to decrease i also
			i -= 2;
		}
	}

	return Convert(elements[0]);
}


