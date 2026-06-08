class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for(int i=0;i<n;i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];
            prod = max(prod,max(prefix,suffix));
        }
        return prod;
    }
};