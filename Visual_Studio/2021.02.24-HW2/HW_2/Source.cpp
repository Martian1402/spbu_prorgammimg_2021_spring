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

template <typename T1, typename T2>
T1 mod(T1 a, T2 b)
{
	return a % b;
}

int operationIndex(char operation)
{
	int index = -2;
	operation == '+' ? index = 0 : operation == '-' ? index = 1 : operation == '*' ? index = 2 : operation == '/' ? index = 3 : operation == '%' ? index = 4 : index = -1;
	return index;
}

template <typename T1, typename T2>
T1 calculate(T1 a, T2 b, char operation)
{
	T1(*ops[5])(T1, T2) = { sum, diff, mult, div, mod };
}


int main(int argc, char** argv)
{
	string oper1 = "--operand1" ;
	string operation = "--operator";
	string oper2 = "--operand2";
	
	string arguments[3] = { oper1, operation, oper2 };
	for (int i = 0; i < argc; ++i)
	{
		if (arguments[0] == argv[i])
		{
			++i;
			arguments[0] = argv[i];
		}
		else if (arguments[1] == argv[i])
		{
			++i;
			arguments[1] = argv[i];
		}
		else if (arguments[2] == argv[i])
		{
			++i;
			arguments[2] = argv[i];
		}
	}
	double a = stod(arguments[0]);
	double b = stod(arguments[2]);
	cout << arguments[0] << " " << arguments[1] << " " << arguments[2] << " = " << calculate(a, b, operationIndex(arguments[1])) << endl;
	//cout << calculate(4.0f, 125, '/');
	return EXIT_SUCCESS;
}