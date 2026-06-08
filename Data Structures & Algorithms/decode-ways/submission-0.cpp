class Solution {
public:
    vector<int> dp;
    int helper(string s,int i,int n){
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        int ans = helper(s,i+1,n);
        if(i+1<n && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')){
            ans += helper(s,i+2,n);
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n,-1);
        return helper(s,0,n);
    }
};
