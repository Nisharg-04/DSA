class Solution {
public:
    static bool cmp(int a , int b){
        return a>b;
    }
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        
        vector<vector<int>> mat = grid;
        
        
        for(int i=0 ; i<grid.size() ; i++){
            sort(mat[i].begin() , mat[i].end() , cmp);
        }
        
        for(int j=0 ; j<mat[0].size() ; j++){
            vector<int> tmp(mat.size());
            for(int i=0 ; i<mat.size() ; i++){
               
                tmp.push_back(mat[i][j]);
            }
           
            sort(tmp.begin() , tmp.end() , cmp);
            
            ans = ans + tmp[0];
        }
        return ans;
    }
};