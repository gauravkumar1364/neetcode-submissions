class Solution {
   public:
    string toposort(vector<vector<int>>& adj,vector<int>& present) {
        vector<int> indegree(26, 0);
        for (auto& it : adj) {
            for (int i = 0; i < it.size(); i++) {
                indegree[it[i]]++;
            }
        }
        queue<int> q;
        int unique_chars = 0;
        for (int i = 0; i < indegree.size(); i++) {
            if(present[i]){
                unique_chars++;
                if (indegree[i] == 0 ) {
                    q.push(i);
                }
            }

        }
        string ans = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans += node + 'a';
            for (auto& it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (ans.size() != unique_chars) {
            return "";
        }
        return ans;
    }

    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> present(26, 0);

        for (auto& word : words) {
            for (char ch : word) {
                present[ch - 'a'] = 1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            if (s1.size() > s2.size() && s1.substr(0, len) == s2.substr(0, len)) return "";
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        return toposort(adj,present);
    }
};
