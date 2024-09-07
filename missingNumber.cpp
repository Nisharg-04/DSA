#include <bits/stdc++.h>
using namespace std;
int abc(vector<int>arr)
{
     sort(arr.begin(), arr.end());
    for (int i = 0; i <= arr.size(); i++)
    {
        if (arr[i] == i)
        {
            continue;
        }
        else
        {
            return i;
        }
    }
}
int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(1);
    // arr.push_back(3);
    // arr.push_back(2);
cout<<abc(arr);
    return 0;
}