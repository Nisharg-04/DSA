#include <bits/stdc++.h>
using namespace std;
int mul(vector<int> &arr, int i, int j, vector<vector<int>> &memo)
{
    if (i + 1 == j)
        return 0;
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        int curr = mul(arr, i, k, memo) + mul(arr, k, j, memo) + arr[i] * arr[k] * arr[j];
        ans = min(curr, ans);
    }
    memo[i][j] = ans;
    return ans;
}
int main()
{
    vector<int> arr = {10, 100, 5, 300, 6};
    vector<vector<int>> memo(arr.size(), vector<int>(arr.size(), -1));
    cout << mul(arr, 0, arr.size() - 1, memo);
}