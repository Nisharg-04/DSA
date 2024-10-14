#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 vector<string>ans;
    void backtrack(vector<string>& ans, string &str, int n, int i, int j) {
        if (str.length() == n * 2) {
            ans.push_back(str);
            return;
        }
        if (i + 1 <= n) {
            str+="(";
            backtrack(ans, str, n, i + 1, j);
            str.pop_back();
        }
        if (j + 1 <= i) {
            str+=")";
            backtrack(ans, str, n, i, j + 1);
            str.pop_back();
        }
    }
    void display()
    {
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }
    vector<string> generateParenthesis(int n) {
       
        string str="(";
        backtrack(ans,str,n,1,0);
        return ans;
    }
};
int main(){
    Solution obj;;
    obj.generateParenthesis(3);
    obj.display();


}