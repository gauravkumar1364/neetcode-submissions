class Solution {
public:
    
    void dfs(vector<vector<int>>& adj,vector<int>& vis,int node){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                count++;
                dfs(adj,vis,i);
            }
        }
        return count;
    }
};
