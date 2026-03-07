class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0) return 1;
        int n = t.size();
        int i =0,j=0;
        while(j<n){
            if(s[i]==t[j]) i++;
        j++;
        }
    return i==s.size() ? 1 : 0;
    }
};