#include <iostream>
using namespace std;
void insertion(int arr[], int &n, int element, int capacity, int index)
{
    if (n >= capacity)
    {
        cout << "Array is full , cannot insert! " << endl;
        return;
    }
    for (int i = n; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    n++;
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int capacity = 10;
    int arr[capacity] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Original array: ";
    display(arr, n);

    int element = 100, index = 5;
    insertion(arr, n, element, capacity, index);

    cout << "Array after insertion: " << endl;
    display(arr, n);

    return 0;
}
