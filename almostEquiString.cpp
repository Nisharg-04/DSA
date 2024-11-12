class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> check(26,0);
        for(int i=0;i<word1.size();i++){
            check[word1[i]-'a']++;
        }

        for (int i=0;i<word2.size();i++){
            check[word2[i]-'a']--;
        }

        for(int i=0;i<check.size();i++){
            cout<<check[i]<<" ";
            if(check[i]>3 || check[i]<-3){
                return false;
            }
        }
        return true;
    }
};