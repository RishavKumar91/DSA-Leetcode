class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        int arr[26] = {0};
        for(int i = 0 ; i < n ; i++) arr[s[i] -'a'] = i;
        string ans  = "";
        bool visit[26] = {0};
        for(int i = 0 ; i < n ; i++){
            int c = s[i] -'a';
            if(visit[s[i]-'a']==1) continue;
            while(ans.size() && ans.back() > s[i] && arr[ans.back()-'a'] > i ){
                visit[ans.back()-'a'] = 0 ; 
                ans.pop_back() ;
            }
            ans.push_back(s[i]); visit[c] = 1;
        }
    return ans;
    }
};