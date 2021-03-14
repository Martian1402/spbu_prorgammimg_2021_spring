#include<iostream>
#include<string>

using namespace std;

//<вещественное число> :: = <мантисса> <порядок> | <знак> <мантисса> <порядок>
//<мантисса> :: = <целое без знака> . <целое без знака>
//<порядок> :: = E <целое без знака> | E <знак> <целое без знака>
//<целое без знака> :: = <цифра> | <цифра> <целое без знака>
//<цифра> :: = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
//< знак > :: = +| -

bool isDigit(char c);
bool isSign(char c);
bool isNatural(string str, int& index);
bool isExponent(string str, int& index);
bool isMantis(string str, int& index);
bool isFP(string str, int& index);


int main(int argc, char** argv)
{
	string str;
	cin >> str;
	int index = 0;

	if (isFP(str, index))
	{
		cout << "=)";
	}
	else
	{
		cout << "=(";
	}
	
	return EXIT_SUCCESS;
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isSign(char c)
{
	return c == '-' || c == '+';
}

bool isNatural(string str, int& index)
{
	if (isDigit(str[index]))
	{
		while (isDigit(str[++index]));
		return true;
	}
	return false;
}

bool isExponent(string str, int& index)
{
	int memIndex = index;
	if (str[index] == 'E')
	{
		++index;
		if (isSign(str[index]) || (isDigit(str[index])))
		{
			++index;
			if (isNatural(str, index))
			{
				return true;
			}
		}
	}
	index = memIndex;
	return false;
}

bool isMantis(string str, int& index)
{
	int memIndex = index;

	if (isNatural(str, index))
	{
		if (str[index] == '.')
		{
			++index;
			if (isNatural(str, index))
			{
				return true;
			}
		}
	}
	index = memIndex;
	return false;
}

bool isFP(string str, int& index)
{
	if (!isSign(str[index]))
	{
		if (!isMantis(str, index))
		{
			return false;
		}
		else
		{
			return isExponent(str, index);
		}
	}
	else
	{
		++index;
		if (isMantis(str, index))
		{
			return isExponent(str, index); 
		}
	}
}