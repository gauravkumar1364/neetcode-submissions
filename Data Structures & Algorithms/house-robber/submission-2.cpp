class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums,int ind,int n){
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = max(
            nums[ind] + helper(nums,ind+2,n),
            helper(nums,ind+1,n) 
            );
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return max(helper(nums,0,n) , helper(nums,1,n));
    }
};
