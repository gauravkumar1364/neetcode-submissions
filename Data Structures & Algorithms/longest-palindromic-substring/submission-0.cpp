class Solution {
   public:
    bool ispal(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0, curr = 0;
        int st = 0, end = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispal(s,i,j)){
                    curr = j-i+1;
                    if(curr>ans){
                        ans = curr;
                        st = i;
                        end = j;
                    }
                }
            }
        }
        string res = "";
        for (int i = st; i <= end; i++) {
            res += s[i];
        }
        return res;
    }
};
