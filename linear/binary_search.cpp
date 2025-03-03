#include <iostream>
using namespace std;
// int linearsearch(int arr[], int size, int target)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == target)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

int binarysearch(int arr[], int size, int target)
{
    int low, mid, high;
     low = 0;
    high = size - 1;
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
    //linear search
    // int arr[] = {1, 2, 3, 54, 22, 5};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int target;

    // cout << "Enter the number you want to search in array: ";
    // cin >> target;
    // int result = linearsearch(arr, size, target);

    // if (result != -1)
    // {
    //     cout << "Elements was found at indedx :" << result << endl;
    // }
    // else
    // {
    //     cout << "Element was not present in given array! ";
    // }
//binary search:
int arr[] = {10,20,30,40,50};
int size = sizeof(arr)/sizeof(arr[0]);
int target;

cout << "Enter the number you want to search in array : ";
cin >> target;
int result = binarysearch(arr, size, target);

if (result != -1)
    {
        cout << "Elements was found at indedx : " << result << endl;
    }
    else
    {
        cout << "Element was not present in given array! ";
    }

    return 0;
}