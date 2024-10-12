class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> f;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                f[nums[i]]++;
            }
        }
        int mi = 0;
        int me = -1;
        for (auto it : f) {
            if (it.second > mi || (it.second == mi && it.first < me)) {
                mi = it.second;
                me = it.first;
            }
        }
        return me;
    }
};