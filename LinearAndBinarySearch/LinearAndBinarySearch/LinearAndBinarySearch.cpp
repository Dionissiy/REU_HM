#include <iostream>
#include <algorithm>
#define SIZE 10

using namespace std;

template<class T>
int linear_search(const T* const arr, const T& key, int size)
{
    for (int i = 0; i < size; ++i)
        if (arr[i] == key)
            return i;
    
    return -1;
}

template<class T>
int binary_search(const T* const arr, const T& key, int size)
{
    int l = 0;
    int r = size - 1;
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

int main()
{
    int arr[SIZE];
    
    for (int i = 0; i < SIZE; ++i)
        cin >> arr[i];

    int key;
    cout << "Input key to find: ";
    cin >> key;

    cout << "What kind of search would you prefer?" << endl;
    cout << "1. Linear search" << endl;
    cout << "2. Binary search" << endl;

    int mode;
    int index;
    cin >> mode;
    switch (mode)
    {
    case(1):
        index = linear_search(arr, key, SIZE);
        break;
    case(2):
        sort(arr, arr + SIZE);
        cout << "Sorted array:" << endl;
        for (int i = 0; i < SIZE; ++i)
            cout << arr[i] << ' ';
        cout << endl;
        index = binary_search(arr, key, SIZE);
        break;
    default:
        cout << "Incorrect Answer";
        return 1;
    }
    
    if (index == -1)
        cout << "key not found" << endl;
    else
        cout << "key has index " << index << endl;


    return 0;
}
