class Solution {
public:
    int loot(vector<int>& hr) {
        vector<int> dp(hr.size());
        dp[0] = hr[0];
        dp[1] = max(hr[0], hr[1]);
        for (int i = 2; i < hr.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + hr[i]);
        }
        return dp[hr.size() - 1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
    
        vector<int> r1(nums.size() - 1);
        vector<int> r2(nums.size() - 1);
        for (int i = 0; i < nums.size() - 1; i++) {
            r1[i] = nums[i];
            r2[i] = nums[i + 1];
        }
        int l1 = loot(r1);
        int l2 = loot(r2);
        return max(l1, l2);
    }
};