class Solution {
public:
    int calSum(string s) {
        int sum = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            string temp = "";
            temp = s[i];
            sum += stoi(temp);
        }
        return sum;
    }
    int getLucky(string s, int k) {
        map<char, int> mpp;
        int n = s.length();
        int x = 'a';
        for (int i = 1; i <= 26; i++) {
            mpp[x] = i;
            x++;
        }
        string temp = "";
        for (int i = 0; i < n; i++) {
            temp += to_string(mpp[s[i]]);
        }
        int ans=0;
        while (k--) {
             ans = calSum(temp);
            temp = to_string(ans);
        }

        return ans;
    }
};