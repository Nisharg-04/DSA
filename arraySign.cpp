class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long prod = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) return 0;
            else if (nums[i] < 0) prod = prod*(-1); 
        }
        if(prod > 0) return 1;
        else return -1;
    }
};cn