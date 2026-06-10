class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int temp = i;
            int cnt = 0;
            while(temp>0){
                temp = temp & (temp-1);
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};