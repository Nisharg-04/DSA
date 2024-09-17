class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mpp1;
        for (int i = 0; i < s1.size();) {
            string temp = "";
            while (i < s1.size() && s1[i] != ' ') {
                temp += s1[i];
                i++;
            }
            mpp1[temp]++;
            i++;
        }
        for (int i = 0; i < s2.size();) {
            string temp = "";
            while (i<s2.size()&&s2[i] != ' ') {
                temp += s2[i];
                i++;
            }
            mpp1[temp]++;
            i++;
        }
        vector<string> ans;
        for (auto it : mpp1) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};