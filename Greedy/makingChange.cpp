#include <bits/stdc++.h>
using namespace std;
class MakingChange
{
    vector<int> coins = {25,10,5,1};
    map<int, int> mpp;

public:
    MakingChange()
    {
        sort(coins.begin(), coins.end(), greater<int>());
    }
    void makeChange(int change)
    {
        int i = 0;
        while (change != 0)
        {
            if (coins[i] <= change)
            {
                int noOfCoins = change / coins[i];
                mpp.insert({coins[i], noOfCoins});
                change = change - noOfCoins * coins[i];
            }
            i++;
        }
    }
    void print()
    {
        auto it = mpp.rbegin();
        while (it != mpp.rend())
        {
            cout << it->first << " -> " << it->second << endl;
            it++;
        }
    }
};
int main()
{
    MakingChange m1;
    int change;
    cout << "Enter The Change Amount :";
    cin >> change;
    m1.makeChange(change);
    m1.print();

    return 0;
}