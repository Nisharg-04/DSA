class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        vis[i][j] = 1;
        int row = i;
        int col = j;
        col--;
        if (col >= 0 && col < vis[0].size() && row >= 0 && row < vis.size() &&
            vis[row][col] == 0 && grid[row][col] == '1') {
            dfs(row, col, vis, grid);
        }
        row = i;
        col = j;
        row--;
        if (col >= 0 && col < vis[0].size() && row >= 0 && row < vis.size() &&
            vis[row][col] == 0 && grid[row][col] == '1') {
            dfs(row, col, vis, grid);
        }
        row = i;
        col = j;
        row++;
        if (col >= 0 && col < vis[0].size() && row >= 0 && row < vis.size() &&
            vis[row][col] == 0 && grid[row][col] == '1') {
            dfs(row, col, vis, grid);
        }
        row = i;
        col = j;
        col++;
        if (col >= 0 && col < vis[0].size() && row >= 0 && row < vis.size() &&
            vis[row][col] == 0 && grid[row][col] == '1') {
            dfs(row, col, vis, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};