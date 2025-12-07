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
	//int size = 
	char r;
	char a;

	for (int i = 0; i < infix.size(); i++)
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

string Reverse(string s)
{
	string a;
	int size = s.size();
	for (int i = size - 1; i >= 0; i--)
	{
		a.push_back(s[i]);
	}
	return a;
}

string InfixToPrefix(string s)
{
	string RevS = Reverse(s);
	int size = RevS.size();

	for (int i = 0; i < size; i++)
	{
		if (RevS[i] == '(')
		{
			RevS[i] = ')';
		}

		else if (RevS[i] == ')')
		{
			RevS[i] = '(';
		}
	}

	string postfix = InfixToPostfix(RevS);

	string prefix = Reverse(postfix);

	return prefix;
}
int evaluateprefix(string prefix)
{

	Stack<int> s(prefix.size());
	int a, b, result=0;
	for (int i = prefix.size(); i >=0; i--)
	{
		char c = prefix[i];
		if (isOperand(c))
		{

			s.push(c - '0');
		}
		else
		{
			a = s.pop();
			b = s.pop();

			if (c == '+')
			{
				
				result = a + b;

			}
			if (c == '-')
			{
				
				result = a - b;
				//s.push(result);
			}
			if (c == '*')
			{
				
				result = a * b;
				//s.push(result);
			}
			if (c == '/')
			{
		
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
	string infix;
	cout << "Enter infix expression: ";
	cin >> infix;

	string postfix = InfixToPostfix(infix);
	string prefix1= InfixToPrefix(infix);

	cout << "Postfix: " << postfix << endl;
	cout << "Prefix: " << prefix1 << endl;
	string prefix = "(2+1)-(2+1)";
	cout << evaluateprefix(prefix) << endl;
	return 0;
}





















