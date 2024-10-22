class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row=INT_MAX;
        int cnt=0;
        int prev=INT_MIN;
        for(int i=0;i<mat.size();i++){
            cnt=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            if(cnt>prev){
                prev=cnt;
                row=i;

            }
        }
        return {row,prev};
    }
};