#include <bits/stdc++.h>
using namespace std;
void findUnion(vector<int> arr1, vector<int> arr2, int n, int m)
{
    vector<int> UnionArr;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (UnionArr.size() == 0 || UnionArr.back() != arr1[i])
            {
                UnionArr.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (UnionArr.size() == 0 || UnionArr.back() != arr2[j])
            {
                UnionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n)
    {
        if (UnionArr.size() == 0 || UnionArr.back() != arr1[i])
        {
            UnionArr.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m)
    {
        if (UnionArr.size() == 0 || UnionArr.back() != arr2[j])
        {
            UnionArr.push_back(arr2[j]);
        }
        j++;
    }
    cout << "UnionArr" << endl;
    for (int i = 0; i < UnionArr.size(); i++)
    {
        cout << UnionArr[i] << " ";
    }
}
int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(3);
    arr1.push_back(4);
    arr1.push_back(5);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(4);
    arr2.push_back(4);
    arr2.push_back(5);
    arr2.push_back(6);

    findUnion(arr1, arr2, 7, 6);

        return 0;
}