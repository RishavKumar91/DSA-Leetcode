class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0 , mxfrq=0,i=0,j=0,n= s.size();
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]==2) {mp[s[i]]--; i++;}
        ans = max(ans,j-i+1);
        j++;
        }
        return ans;
    }
};