class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> st;
        int m = s.size(); int n = t.size();
        for(int i =0;i<m;i++){
            st[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(st[t[i]]==0) return t[i];
            st[t[i]]--;
        }
    return 'z';
    }
};