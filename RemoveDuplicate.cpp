#include <iostream>
#include <vector>
using namespace std;
int removeDups(vector<int> &arr, int n)
{
    int fptr = 0;
    int sptr = 1;
    int i = 0;
    while (sptr != n)
    {
        if (arr[fptr] == arr[sptr])
        {

            sptr++;
        }
        else
        {
            arr[i] = arr[fptr];
            i++;
            fptr = sptr;
            sptr++;
        }
    }
    return i;
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(5);
    cout << removeDups(arr, 10);
    return 0;
}