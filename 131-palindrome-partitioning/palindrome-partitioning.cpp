class Solution {
public:
vector<vector<string>> ans;
int n;
    bool ispalindrome(string &s , int i , int j){
        while(i<j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
    return 1;
    }
    void hlpr(vector<string> &st ,string &s , int startix){
        if(startix == n){
            ans.push_back(st);
            return ;
        }
        for(int lastix = startix ; lastix < n ; lastix++){
            if(!ispalindrome(s,startix,lastix)) continue;
            st.push_back(s.substr(startix,lastix-startix+1));
            hlpr(st,s,lastix+1);
            st.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        string tmp ;
        n = s.size();
        vector<string> st;
        hlpr(st,s,0);
        return ans;
    }
};