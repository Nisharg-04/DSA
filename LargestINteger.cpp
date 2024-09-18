class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> sorted;
        for (int i = 0; i < nums.size(); i++) {
            sorted.push_back(to_string(nums[i]));
        }
        sort(
            sorted.begin(), sorted.end(),
            [](const string& a, const string& b) { return (b + a) > (a + b); });
        string ans = "";
        for (int i = sorted.size() - 1; i >= 0; i--) {
            ans += sorted[i];
        }
        if(ans[0]=='0')return "0";
        return ans;
    }
};