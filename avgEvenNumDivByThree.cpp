class Solution {
typedef long long ll;
public:
    int averageValue(vector<int>&v) {
        ll sum=0, cnt=0;
        for(ll it:v){
            if(!(it&1) && !(it%3)){
                ++cnt, sum+=it;
            }
        }
        if(!cnt){
            return 0;
        }
        return sum/cnt;
    }
};