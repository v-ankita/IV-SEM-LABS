#include <iostream>
#include <math.h>
using namespace std;
int GetMaxVal(int *arr, int n, int *weight, int *value, int capacity)
{
	int snum = 0;
	int max = 0;
	while (snum < pow(2, n))
	{
		int val = 0;
		int w = 0;
		for (int i = 0; i < n; ++i)
		{
			if ((snum &(1 << i)) != 0)
			{
				val += value[i];
			}
		}

		max = val;
	}

	{
		int v = 0;
		int wt = 0;
		for (int i = 0; i < n; ++i)
		{
			if ((snum &(1 << i)) != 0)
			{
				v += value[i];
			}
		}

		if (v == max && wt <= capacity)
		{
			cout << "\n The Most valuable ItemSet is: ";
			for (int i = 0; i < n; ++i) {}
		}

		++snum;
	}
    return snum;
}

int main()
{
	int n;
	int capacity;
	cout << "Enter the number of items: ";
	cin >> n;
	int arr[n];
	int weight[n];
	int value[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	cout << "Enter weight of items: ";
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}

	cout << "Enter value of items: ";
	for (int i = 0; i < n; i++)
	{
		cin >> value[i];
	}

	cout << "Enter knapsack capacity: ";
	cin >> capacity;
	int max = GetMaxVal(arr, n, weight, value, capacity);
    cout<<max;
	// Print(arr, n, weight, value, capacity, max);
	cout << endl;
}