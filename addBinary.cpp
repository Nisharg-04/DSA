class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string ans = "";
        while (i >= 0 && j >= 0) {
            if (a[i] == '1' && b[j] == '1') {
                if (c == 1) {
                    ans.push_back('1');
                    c = 1;
                } else {
                    ans.push_back('0');
                    c = 1;
                }
            } else if (a[i] == '1' && b[j] == '0' ||
                       a[i] == '0' && b[j] == '1') {
                if (c == 1) {
                    ans.push_back('0');
                    c = 1;
                } else {
                    ans.push_back('1');
                    c = 0;
                }
            } else {
                if (c == 1) {
                    ans.push_back('1');
                    c = 0;
                } else {
                    ans.push_back('0');
                    c = 0;
                }
            }
            i--;
            j--;
        }
        while (i >= 0) {
            if (a[i] == '1') {
                if (c == 1) {
                    ans.push_back('0');
                    c = 1;
                } else {
                    ans.push_back('1');
                    c = 0;
                }

            } else {
                if (c == 1) {
                    ans.push_back('1');
                    c = 0;
                } else {
                    ans.push_back('0');
                    c = 0;
                }
            }
            i--;
        }
        while (j >= 0) {
            if (b[j] == '1') {
                if (c == 1) {
                    ans.push_back('0');
                    c = 1;
                } else {
                    ans.push_back('1');
                    c = 0;
                }

            } else {
                if (c == 1) {
                    ans.push_back('1');
                    c = 0;
                } else {
                    ans.push_back('0');
                    c = 0;
                }
            }
            j--;
        }
        if (c == 1) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};