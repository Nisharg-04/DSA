class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid2,
             vector<vector<int>>& grid1, int& flag) {
        if (grid1[i][j] == 0) {
            flag = 0;
        }
        vis[i][j] = 1;
        int row = i;
        int col = j;
        col--;
        if (col >= 0 && col < vis[0].size() && row >= 0 && row < vis.size() &&
            vis[row][col] == 0 && grid2[row][col] == 1) {
            dfs(row, col, vis, grid2, grid1, flag);
        }
        row = i;
        col = j;
        row--;
        if (col >= 0 && col < vis[0].size() && row >= 0 && row < vis.size() &&
            vis[row][col] == 0 && grid2[row][col] == 1) {
            dfs(row, col, vis, grid2, grid1, flag);
        }
        row = i;
        col = j;
        row++;
        if (col >= 0 && col < vis[0].size() && row >= 0 && row < vis.size() &&
            vis[row][col] == 0 && grid2[row][col] == 1) {
            dfs(row, col, vis, grid2, grid1, flag);
        }
        row = i;
        col = j;
        col++;
        if (col >= 0 && col < vis[0].size() && row >= 0 && row < vis.size() &&
            vis[row][col] == 0 && grid2[row][col] == 1) {
            dfs(row, col, vis, grid2, grid1, flag);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        vector<vector<int>> vis(grid2.size(), vector<int>(grid2[0].size(), 0));
        int cnt = 0;
        int flag = 1;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid1[i][j] == 1 && grid2[i][j] == 1 && vis[i][j] == 0) {
                    dfs(i, j, vis, grid2, grid1, flag);
                    if (flag)
                        cnt++;
                    else
                    flag=1;
                        
                }
            }
        }
        return cnt;
    }
};