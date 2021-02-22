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
	void printBits(int x);
	cout << ".";
	
	for (int i = 0; i < bitlength; ++i)
	{
		

		
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



	}
}


int main()

{
	int z = 32767;
	long x = 4294967295;
	long long c = 18446744073709551615;
	float v;
	double b;
	long double n;

	printBits(z);
	return EXIT_SUCCESS;
}