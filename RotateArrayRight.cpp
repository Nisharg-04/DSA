#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int> &arr, int k)
{

    int n = arr.size();
    int d = k % n;
    vector<int> temp;
    for (int i = 0; i < n - d; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i = 0; i < d; i++)
    {
        arr[i] = arr[n - d + i];
    }
    int j = 0;
    for (int i = d; i < n; i++)
    {
        arr[i] = temp[j];
        j++;
    }
}

int main()
{
    vector<int> arr;
    for (int i = 1; i < 8; i++)
    {
        arr.push_back(i);
    }
    rotate(arr, 3);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
