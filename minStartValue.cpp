class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        int extra=0;
        int sum=0;
      for(int i=0;i<n;i++){
          sum+=nums[i];
          if(sum<1){
              extra=extra+(1-sum);
              sum=1;
          }
      }  
      if(extra==0){
          extra=1;
      }
      return extra;
    }
};