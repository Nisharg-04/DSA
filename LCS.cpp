#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 = "ABCD";
    string s2 = "ACBD";
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
    string ans;
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < dp[0].size(); i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Max : " << dp[dp.size() - 1][dp[0].size() - 1] << endl;
    int i = s1.size();
    int j = s2.size();
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    cout << ans;
}