class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1,mp2;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(mp1.find(s[i])==mp1.end()) mp1[s[i]] =t[i];
            else if(mp1[s[i]] != t[i]) return 0;
            if(mp2.find(t[i])==mp2.end()) mp2[t[i]] =s[i];
            else if(mp2[t[i]] != s[i]) return 0;
        }
        return 1;
    }
};