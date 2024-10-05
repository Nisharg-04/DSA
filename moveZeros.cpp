#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int j = -1;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            j = i;
           
            break;
        }
       
    }
    for (int i = j + 1; i < n;)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
            cout<<"i= "<<i<<" "<<"j= "<<j<<endl;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(12);
    moveZeroes(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}