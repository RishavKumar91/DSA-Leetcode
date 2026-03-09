class Solution {
public:
    int minimizedStringLength(string s) {
        int n = s.size();
        // string ans = "";
        int count = 0;
        vector<int> visit(26,0);
        for(int i = 0;i<n;i++){
            if(!(visit[s[i]-'a'])) {visit[s[i]-'a'] = 1 ; count++;}
        }
    return count;
    }
};