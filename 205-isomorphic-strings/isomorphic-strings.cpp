class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for(int  i =0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j] && t[i]!=t[j]) return 0;
                if(t[i]==t[j] && s[i]!=s[j]) return 0;
            }
        }
        return 1;
    }
};