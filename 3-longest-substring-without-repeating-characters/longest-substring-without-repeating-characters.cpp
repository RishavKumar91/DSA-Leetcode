class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0 , n = s.size();
        int j = 0 , i = 0;
        vector<int> mp(256 , -1);
        for(int j = 0 ; j < n ; j++){
            int ch = s[j] ; 
            if(mp[ch] != -1){
                i = max(i,mp[ch]+1);
            }
            mp[ch] = j;
            ans = max(ans , j - i + 1);
        }
    return ans; 
    }
};