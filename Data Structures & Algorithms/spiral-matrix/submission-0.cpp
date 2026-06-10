class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        if(matrix.empty()) return {};

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;

        int total = n * m;
        int i = 0, j = 0;

        while(ans.size() < total) {

            // → right
            while(i < m && vis[j][i] == 0) {
                ans.push_back(matrix[j][i]);
                vis[j][i] = 1;
                i++;
            }
            i--; j++;

            // ↓ down
            while(j < n && vis[j][i] == 0) {
                ans.push_back(matrix[j][i]);
                vis[j][i] = 1;
                j++;
            }
            j--; i--;

            // ← left
            while(i >= 0 && vis[j][i] == 0) {
                ans.push_back(matrix[j][i]);
                vis[j][i] = 1;
                i--;
            }
            i++; j--;

            // ↑ up
            while(j >= 0 && vis[j][i] == 0) {
                ans.push_back(matrix[j][i]);
                vis[j][i] = 1;
                j--;
            }
            j++; i++;
        }

        return ans;
    }
};
