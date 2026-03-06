class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1,mp2;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(mp1.count(s[i]) && mp1[s[i]]!=t[i]) return 0;
            if(mp2.count(t[i]) && mp2[t[i]]!=s[i]) return 0;
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
    return 1;
    }
};