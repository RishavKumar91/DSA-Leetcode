class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> sr;
        int ans = 0;
        for(int i =0;i<s.size();i++){
            sr.insert(s[i]);
            if(sr.size() == (i+1)%3) ans++;
        }
    return ans;
    }
};