#include <iostream>
using namespace std;

int binarySearch(int *arr, int l, int u, int value)
{
    if(l == u) return -1;
    int mid = (l + u)/2;
    if(arr[mid] == value)
    {
        return mid;
    }
    else if(arr[mid] > value)
    {
        return binarySearch(arr, l, mid - 1, value);
    }
    else if(arr[mid] < value)
    {
        return binarySearch(arr, mid + 1, u, value);
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,4,7,8,10,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << binarySearch(arr, 0, n, 15);
    return 0;
}
