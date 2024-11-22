#include<bits/stdc++.h>
using namespace std;

map<int, vector<char>> m = {
    {2, {'a', 'b', 'c'}}, 
    {3, {'d', 'e', 'f'}},
    {4, {'g', 'h', 'i'}},
    {5, {'j', 'k', 'l'}},
    {6, {'m', 'n', 'o'}},
    {7, {'p', 'q', 'r'}},
    {8, {'s', 't', 'u'}},
    {9, {'v', 'w', 'x', 'z'}}
};

void keyPad(vector<int> v, string& curr, vector<string>& res, int i)
{
    if(i == v.size())
    {
        res.push_back(curr);
        return;
    }

    int digit = v[i];
    for(char c : m[digit])
    {
        curr.push_back(c);
        keyPad(v, curr, res, i+1);
        curr.pop_back();
    }
}

int main()
{
    vector<int> v = {9, 3, 4};
    string curr = "";
    vector<string> res;

    keyPad(v, curr, res, 0);
    
    for(string s : res)
    {
        cout<<s<<endl;
    }
}