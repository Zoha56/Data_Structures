// Postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include<array>
#include"Stack.cpp"
using namespace std;

int Precedence(char c)   //checking precedence to push in stack
{
	if (c == '+' || c == '-')
	{
		return 1;
	}

	if (c == '*' || c == '/')
	{
		return 2;
	}
}

bool isOperator(char c)  //checking if the entered character is an operator
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool isOperand(char c)  //checking if the entered character is an operator 
{
	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool isOpeningBracket(char c)  //checking for opening bracket
{
	if (c == '(')
	{
		return true;
	}

	else
	{
		return false;
	}

}

bool isClosingBracket(char c)  //checking for closing bracket
{
	if (c == ')')
	{
		return true;
	}

	else
	{
		return false;
	}
}

string InfixToPostfix(string infix)
{
	Stack<int> st(100);  //only operands will go in the stack
	string postfix = "";
	int size = infix.size();
	char r;
	char a;

	for (int i = 0; i < size; i++)
	{
		r = infix[i];

		if (isOperand(r) == true)
		{
			postfix.push_back(r); //appending the char 
		}

		else if (isOpeningBracket(r) == true)
		{
			st.push(r);
		}

		else if (isClosingBracket(r) == true)
		{
			while (!st.isempty() && !isOpeningBracket(st.getStack()))
			{
				a = st.pop();
				postfix.push_back(a);
			}

			st.pop(); //removing the found opening bracket
		}

		else if (isOperator(r) == true)
		{
			while (!st.isempty() && Precedence(st.getStack()) >= Precedence(r))
			{
				a = st.pop();
				postfix.push_back(a);
			}

			st.push(r);
		}

	}

	while (!st.isempty())
	{
		a = st.pop();
		postfix.push_back(a);
	}

	return postfix;

}
int evaluation(string postfix)
{
	Stack<int> s(postfix.size());
	int a, b, result;
	for (int i = 0; i < postfix.size(); i++)
	{
		char c = postfix[i];
		if (isOperand(c))
		{
			
			s.push(c-'0');
		}
		else
		{
			
			if (c == '+')
			{
				a = s.pop();
				b = s.pop();
				result = a + b;
				
			}
			if (c == '-')
			{
				a = s.pop();
				b = s.pop();
				result = a - b;
				//s.push(result);
			}
			if (c == '*')
			{
				a = s.pop();
				b = s.pop();
				result = a * b;
				//s.push(result);
			}
			if (c == '/')
			{
				a = s.pop();
				b = s.pop();
				result = a + b;
				//s.push(result);
			}
			s.push(result);
		}
	}
	result = s.pop();
	return result;

	 
	
}

int main()
{
	string s;
	string result;

	cout << "Enter your string without spaces" << endl;
	cin >> s;

	result = InfixToPostfix(s);

	cout << "Postfix expression:" << endl;
	cout << result << endl;
	string postfix = "2532+*/";
	int re = evaluation(postfix);
	cout << re << endl;
	return 0;

}























// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
