#include <iostream>
using namespace std;

int linearsearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {23, 4, 2, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 2;

    int result = linearsearch(arr, size, target);

    (result != 1) ? cout << "Element was found at an index " << result
                  : cout << "Element was not found ";

    return 0;
}
