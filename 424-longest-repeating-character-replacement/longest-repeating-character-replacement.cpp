class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size() ,i =0,j=0,ans=0,maxx=0;
        unordered_map<char ,int> mp;
        while(j<n){
            mp[s[j]]++;
            maxx = max(maxx,mp[s[j]]);
            if(j-i+1-maxx>k) { mp[s[i]]--; i++;}
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};