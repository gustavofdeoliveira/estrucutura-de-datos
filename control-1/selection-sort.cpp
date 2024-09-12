#include <iostream>

using namespace std;

void selectionSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }
        std::swap(array[min_idx], array[i]);
    }
}

int main()
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    selectionSort(array, n);


    return 0;
}
