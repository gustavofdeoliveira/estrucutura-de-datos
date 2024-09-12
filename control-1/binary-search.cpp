#include <iostream>

using namespace std;

int binarySearch(int array[], int low, int hight, int target)
{

    while (low <= hight)
    {
        int mid = low + (hight - low) / 2;
        if (array[mid] == target)
        {
            return mid;
        }
        if (array[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            hight = mid - 1;
        }
    }
    return -1;
}

int main()
{

    return 0;
}