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

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 64, 64, 13, 1, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    int element = 99;
    int indexsearch = linearsearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, indexsearch);

    return 0;
}
