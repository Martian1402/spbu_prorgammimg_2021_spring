#include<iostream>;
#include<string>;

using namespace std;

template <typename T1, typename T2>
T1 sum(T1 a, T2 b)
{
	return a + b;
}
template <typename T1, typename T2>
T1 diff(T1 a, T2 b)
{
	return a - b;
}

template <typename T1, typename T2>
T1 mult(T1 a, T2 b)
{
	return a * b;
}

template <typename T1, typename T2>
T1 div(T1 a, T2 b)
{
	return a / b;
}

template<typename T1, typename T2>
T1 mod(T1 a, T2 b)
{
	while (a > b) a -= b;
	return a;
}

int operationIndex(char operation)
{
	switch (operation)
	{
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		case '%': return 4;
	}
	return 0;
}

template <typename T1, typename T2>
T1 calculate(T1 a, T2 b, char operation)
{
	T1(*ops[5])(T1, T2) = { sum, diff, mult, div, mod };
	return ops[operationIndex(operation)](a, b);
}

bool isInt(string str)
{
	return str.find('.') == -1;
}

bool isDouble(string str)
{
	return str.find('.') != -1;
}

int main(int argc, char** argv)
{
	string oper1;
	string operation;
	string oper2;
	
	if (strcmp(argv[1], "--operator") == 0) 
	{
		operation = argv[2]; oper1 = argv[4]; oper2 = argv[6];
	}
	if (strcmp(argv[3], "--operator") == 0)
	{
		operation = argv[4]; oper1 = argv[2]; oper2 = argv[6];
	}
	if (strcmp(argv[5], "--operator") == 0)
	{
		operation = argv[6]; oper1 = argv[4]; oper2 = argv[2];
	}
	cout << oper1 << " ";
	cout << operation << " ";
	cout << oper2 << " = ";
	if (isInt(oper1) && isInt(oper2))
	{
		cout << calculate(stoi(oper1), stoi(oper2), operation[0]) << endl;
	}
	else if (isDouble(oper1) && isDouble(oper2))
	{
		cout << calculate(stod(oper1), stod(oper2), operation[0]) << endl;
	}
	else
	{
		if (isInt(oper1))
		{
			cout << calculate(stoi(oper1), stod(oper2), operation[0]) << endl;
		}
		else
		{
			cout << calculate(stod(oper1), stoi(oper2), operation[0]) << endl;
		}
	}

	return EXIT_SUCCESS;
}