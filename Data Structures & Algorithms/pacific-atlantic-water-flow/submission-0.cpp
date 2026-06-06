class Solution {
public:
    int dr[4] = {-1, 0, 1, 0}; // row change
    int dc[4] = {0, 1, 0, -1}; // col change
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int row, int col, int n, int m) {

        if (vis[row][col])
            return;
        vis[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if ((nrow < n && ncol < m && nrow >= 0 && ncol >= 0) &&
                !vis[nrow][ncol] && heights[row][col] <= heights[nrow][ncol]) {
                dfs(heights,vis, nrow, ncol, n, m);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            dfs(heights, pac, i, 0, n, m);
            dfs(heights, atl, i, m - 1, n, m);
        }

        for (int j = 0; j < m; j++) {
            dfs(heights, pac, 0, j, n, m);
            dfs(heights, atl, n - 1, j, n, m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (atl[i][j] == 1 && pac[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};