class Solution {
public:
    void findcombinations(int index,vector<int> &candidates, int target,vector<vector<int>> &ans,vector<int> &ds){
        // Base case
        if(index == candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        //picking the element
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            findcombinations(index,candidates,target-candidates[index],ans,ds);
            ds.pop_back();
        }
        findcombinations(index+1,candidates,target,ans,ds);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        findcombinations(0,candidates,target,ans,ds);
        return ans;
    }
};