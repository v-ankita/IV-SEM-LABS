#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    int min_idx;
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i; // coz pehle ke elements are sorted
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx]) // iterate over remaining array and if any element is smaller than current min(which is 1stelem of unsorted part then make that as index of min)
                min_idx = j;
        }
        // Swap the found minimum element with the first element of the unsorted part
        swap(&arr[min_idx], &arr[i]);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements of the array ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The entered array is : " << endl;
    printArray(arr, n);

    cout << "\nThe Sorted array is : ";
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}