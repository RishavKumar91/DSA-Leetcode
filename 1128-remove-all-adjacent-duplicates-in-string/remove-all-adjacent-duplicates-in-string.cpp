class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string ans = "";
        // stack<char> chck;
        for(int i = 0;i<n;i++){
            // if(chck.top()==s[i]) s.pop_back();
            // else chck.push_back();
            if(ans.size()>0 && ans.back() == s[i]) ans.pop_back();
            else ans.push_back(s[i]);
        }
    return ans;
    }
};