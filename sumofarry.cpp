#include <iostream>
using namespace std;
int sum(int *arr, int size)
{
    if (size == 0)
    {
        return 0;
    }
    else
    {
        int s = sum(arr + 1, size - 1) + arr[0];
        return s;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7};
    int a = sum(arr, 6);
    cout<<a;
    return 0;
}