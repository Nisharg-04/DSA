class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0;
        long long temp = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            // cout<<s[i]<<endl;
            if (s[i] == '0') {
                temp++;
            } else {
                cnt += temp;
                // temp = 0;
            }
        }
        return cnt;
    }
};