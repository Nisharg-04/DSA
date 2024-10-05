class Solution {
public:
    int solve(int sum){
        int ans=0;

        while(sum!=0){
            int temp=sum%10;
            ans+=pow(temp,2);
            sum=sum/10; 
            }
            cout<<ans<<endl;
            return ans;
    }
    bool isHappy(int n) {
        unordered_set<int>s;
        while(s.find(n)==s.end()){
               s.insert(n);
            if(n==1)return true;

            // if(floor(log10(n)+1)==1)return false;
            n=solve(n);
            if(n==1)return true;
          
         
        }
        return false;
       
    }
};