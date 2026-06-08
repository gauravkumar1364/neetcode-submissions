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
        if(n==1) return nums[0];
        dp.assign(n, -1);
        int case1 = helper(nums,0,n-1);
        dp.assign(n, -1);
        int case2 = helper(nums,1,n);
        return max(case1 , case2 );
    }
};
