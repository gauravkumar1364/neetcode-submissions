class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(auto it : intervals){
            // case 1
            if(it[1]<newInterval[0]){
                ans.push_back(it);
            }
            // case 2
            else if(it[0] > newInterval[1]){
                ans.push_back(newInterval);
                newInterval = it;
            }
            // case 3
            else{
                newInterval[0] = min(it[0],newInterval[0]);
                newInterval[1] = max(it[1] , newInterval[1]);

            }
            
        }
        ans.push_back(newInterval);
        return ans;
    }
};
