#include <iostream>

using namespace std;

void countingSort(int array[], int n, int max)
{
    int count[max + 1] = {0};

    int sortedArray[n];

    // count each element
    for (int i = 0; i < n; i++)
    {
        count[array[i]]++;
    }

    // update count array
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // build sorted array
    for (int i = n - 1; i >= 0; i--)
    {
        sortedArray[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // copy sorted array to original array
    for (int i = 0; i < n; i++)
    {
        array[i] = sortedArray[i];
    }

    cout << "Sorted array: \n";

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}