class Solution {
public:
    string intToRoman(int num) {
        map<int, string> mpp;
        mpp.insert({1000, "M"});
        mpp.insert({900,"CM"});
        mpp.insert({500, "D"});
        mpp.insert({400,"CD"});
        mpp.insert({100, "C"});
        mpp.insert({90,"XC"});
        mpp.insert({50, "L"});
        mpp.insert({40,"XL"});
        mpp.insert({10, "X"});
        mpp.insert({9,"IX"});
        mpp.insert({5, "V"});
        mpp.insert({4,"IV"});
        mpp.insert({1, "I"});

        string ans="";
        for(auto it=mpp.rbegin();it!=mpp.rend();it++){
            int a=it->first;
            string b=it->second;
            while(num>=a){
                ans+=b;
                num-=a;
            }
        }
        return ans;

       
    }
};