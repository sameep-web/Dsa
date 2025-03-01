#include <iostream>
using namespace std;
int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[], int size, int element)
{
    int mid, high, low;
    low = 0;
    high = size - 1;
    while (low <= high)
    {

        mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // unsorted array for linear search
    // int arr[] = {1, 2, 3, 4, 5, 64, 64, 13, 1, 5, 6};
    // int size = sizeof(arr) / sizeof(int);

    // sorted array for binary search
    int arr[] = {1, 2, 3, 4, 5, 6, 64, 333, 441, 500, 600};
    int size = sizeof(arr) / sizeof(int);
    int element = 64;
    int indexsearch = binarysearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, indexsearch);

    return 0;
}
