#include <iostream>
using namespace std;

int binarysearch(int arr[], int size, int target)
{

    int low = 0, mid, high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
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
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter the element you want to search in array:";
    cin >> target;

    int result = binarysearch(arr, size, target);

    if (result != -1)
    {
        cout << "The element in array is placed at index " << result << endl;
    }
    else
    {
        cout << "The element is not found in the array:" << endl;
    }
    return 0;
}
