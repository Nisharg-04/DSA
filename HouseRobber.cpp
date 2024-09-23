class Solution {
public:
    int rob(vector<int>& nums) {
        int l=nums.size();
        if(l==1){
            return nums[0];
        }
        if(l==2){
            return max(nums[0],nums[1]);
        }
        vector<int> res(l,0);
        res[0]=nums[0];
        res[1]=max(nums[0],nums[1]);
        for(int i=2;i<l;i++){
            res[i]=max(res[i-2]+nums[i],res[i-1]);
        }
        return max(res[l-1],res[l-2]);
    }
};