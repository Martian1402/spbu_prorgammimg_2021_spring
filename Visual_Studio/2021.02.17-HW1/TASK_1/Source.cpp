#include<iostream>
#include<math.h>
using namespace std;

void printBits(int a)
{
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned int bit = a;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

void printBits(long a)
{
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned long bit = a;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

void printBits(long long a)
{
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned long long bit = a;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

void printBits(float a)
{
	int bitlength = sizeof(a) * 8;
	float x, y;
	y = modff(a, &x);
	int b = (int)x;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned int bit = b;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
	cout << ".";
	float r = 0.0;
	int i = 0;
	while ((y != 0) || (i < 8))
	{
		float bit = y;
		y = modff(bit * 2, &r);
		++i;
		cout << r;
	}
}

void printBits(double a)
{
	int bitlength = sizeof(a) * 8;
	double x, y;
	y = modf(a, &x);
	int b = (int)x;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned int bit = b;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
	cout << ".";
	double r = 0.0;
	int i = 0;
	while ((y != 0) || (i < 16))
	{
		double bit = y;
		y = modf(bit * 2, &r);
		++i;
		cout << r;
	}
}

void printBits(long double a)
{
	int bitlength = sizeof(a) * 8;
	long double x, y;
	y = modfl(a, &x);
	int b = (int)x;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned int bit = b;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
	cout << ".";
	long double r = 0.0;
	int i = 0;
	while ((y != 0) || (i < 18))
	{
		long double bit = y;
		y = modfl(bit * 2, &r);
		++i;
		cout << r;
	}
}


int main()
{
	int i;
	long l;
	long long ll;
	float f;
	double d;
	long double ld;
	cin >> i;
	printBits(i);
	cout << endl;

	cin >> l;
	printBits(l);
	cout << endl;

	cin >> ll;
	printBits(ll);
	cout << endl;

	cin >> f;
	printBits(f);
	cout << endl;

	cin >> d;
	printBits(d);
	cout << endl;

	cin >> ld;
	printBits(ld);
	cout << endl;
	return EXIT_SUCCESS;
}