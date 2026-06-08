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
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j = i;j<n;j++){
                if(ispal(s,i,j)) count++;
            }
        }
        return count;
    }
};

