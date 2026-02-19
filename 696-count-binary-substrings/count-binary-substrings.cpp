class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev =0;
        int now = 1;
        int ans = 0;
        for(int i =1;i<s.size();i++){
            if(s[i]==s[i-1]) {
                now++;
            }
            else {
                ans+=min(prev,now);
                prev = now;
                now = 1;
            }
        }
    return ans + min(prev,now);
    }
};