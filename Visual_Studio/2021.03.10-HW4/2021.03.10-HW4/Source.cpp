#include<iostream>

using namespace std;

void fillArray(int* a, int len);
void printArray(int* a, int len);
void swap(int& a, int& b);
void mixArray(int* a, int len);
void bubbleSort(int* a, int len, int& bubbleCOM, int& bubblePER);
void insertionSort(int* a, int len, int& insertionCOM, int& insertionPER);
void selectionSort(int* a, int len, int& selectoinCOM, int& selectoinPER);
void printCount(int a, int b);

int main(int argc, char** argv)
{
	for (int len = 5; len <= 20; len += 5)
	{
		int* a = new int[len];
		fillArray(a, len);
		printArray(a, len);

		cout << "Bubble sort" << endl;
		int bubbleCOM = 0;
		int bubblePER = 0;
		for (int i = 0; i < 1000; ++i)
		{
			mixArray(a, len);
			bubbleSort(a, len, bubbleCOM, bubblePER);
		}
		printCount(bubbleCOM, bubblePER);

		cout << "Insertion sort" << endl;
		int insertionCOM = 0;
		int insertionPER = 0;
		for (int i = 0; i < 1000; ++i)
		{
			mixArray(a, len);
			insertionSort(a, len, insertionCOM, insertionPER);
		}
		printCount(insertionCOM, insertionPER);

		cout << "Selectoin sort" << endl;
		int selectoinCOM = 0;
		int selectoinPER = 0;
		for (int i = 0; i < 1000; ++i)
		{
			mixArray(a, len);
			selectionSort(a, len, selectoinCOM, selectoinPER);
		}
		printCount(selectoinCOM, selectoinPER);

		delete[] a;
	}

	return EXIT_SUCCESS;
}

void fillArray(int * a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 90 + 10;
	}
}

void printArray(int * a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void swap(int & a, int & b)
{
	int c = a;
	a = b;
	b = c;
}

void mixArray(int * a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		swap(a[i], a[rand() % len]);
	}
	printArray(a, len);
}

void bubbleSort(int * a, int len, int& bubbleCOM, int& bubblePER)
{
	for (int i = 0; i < len - 2; ++i)
	{
		for (int j = 1; j < len - i - 1; ++j)
		{
			++bubbleCOM;
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				++bubblePER;
			}
		}
	}
}

void insertionSort(int * a, int len, int& insertionCOM, int& insertionPER)
{
	for (int i = 1; i < len; ++i)
	{
		int t = a[i];
		int j = i;
		++insertionCOM;
		while (j > 0 && a[j - 1] > t)
		{
			a[j] = a[j - 1];
			++insertionPER;
			--j;
		}
		a[j] = t;
	}
}

void selectionSort(int * a, int len, int& selectoinCOM, int& selectoinPER)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int index = i;
		for (int j = i + 1; j < len; ++j)
		{
			++selectoinCOM;
			if (a[j] < a[index])
			{
				index = j;
			}
		}
		swap(a[i], a[index]);
		++selectoinPER;
	}
}

void printCount(int a, int b)
{
	cout << "comparison's count: " << a / 1000 << endl;
	cout << "permutation's count: " << b / 1000 << endl;
}

