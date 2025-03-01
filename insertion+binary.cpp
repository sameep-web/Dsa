#include <iostream>
using namespace std;
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int insertion(int arr[], int &size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int binarysearch(int arr[], int size, int num)
{
    int low = 0;
    int mid;
    int high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        if (arr[mid] < num)
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
    int arr[100] = {1, 2, 3, 45, 66, 88};
    int size = 6;
    int index = 0;
    int element = 35;
    cout << "before insertion: ";
    display(arr, size);

    int num;
    cout << "Enter the element you want to search in array: ";
    cin >> num;

    int result = binarysearch(arr, size, num);

    if (result != -1)
    {
        cout << "The element in array is found at index : " << result<<endl;;
    }
    else
    {
        cout << "The element was not found in an array " << endl;
    }


    if (insertion(arr, size, element, 100, index) == 1)
    {
        size += 1;
        cout << "After insertion: ";
        display(arr, size);
    }
    else
    {
        cout << "Insertion is failed : Array is fulled " << endl;
    }
    
    return 0;
}
