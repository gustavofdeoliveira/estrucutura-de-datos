#include <iostream>

using namespace std;

void insertionSort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }

    cout << "Sorted array: \n";

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main()
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};

    insertionSort(array, 1);

    return 0;
}