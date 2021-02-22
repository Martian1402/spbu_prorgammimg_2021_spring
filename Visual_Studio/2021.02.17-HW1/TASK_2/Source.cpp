#include<iostream>
#include<math.h>
using namespace std;

double average(int n, ...)
{
	double result = 0.0;
		for (int i = 0; i < n; ++i)
		{
			int* ptr = &n + 1 + i;
			result += (double)*ptr;
		}
		return (result/n);
}

int main()
{
	cout << average(6,2,25,100,3,5,7);
	return EXIT_SUCCESS;
}
