class Solution {
public:
    bool cs( vector<vector<int>>& graph, vector <int> &vis,int src){
        // int n = prerq.size(),m=prerq[0].size();
        if (vis[src] == 1) return false;
        if (vis[src] == 2) return true;
        vis[src] = 1;
        for (int neighbor : graph[src]) {
            if (!cs(graph, vis, neighbor))
            return false;
        }
        vis[src] = 2; // mark as visited
        return true;
    }
    bool canFinish(int numcourses, vector<vector<int>>& prerq) {
        vector <int> vis(numcourses,0);
        vector<vector<int>> graph(numcourses);
        for(auto p: prerq){
            graph[p[1]].push_back(p[0]);

        }
        for(int i=0;i<numcourses;i++){
            if (!cs(graph, vis, i)) return false;
        }
        return true;

    }
};