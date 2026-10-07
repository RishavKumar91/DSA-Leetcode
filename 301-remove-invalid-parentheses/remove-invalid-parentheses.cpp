class Solution {
public:
int n ;
unordered_set<string> ans ; 
int sz = 0 ;
    void hlpr(int ix , string &tmp , string &s,int count){
        if(count < 0) return ;
        if(count == 0){
            if(tmp.size() > sz) { ans.clear(); sz = tmp.size(); }
            if(sz == tmp.size()) ans.insert(tmp);
        }
        for(int i = ix  ; i < n ; i++){
            if(s[i] >= 'a' && s[i] <= 'z') {
                tmp.push_back(s[i]);
                hlpr(i + 1, tmp, s, count);
                tmp.pop_back();
                continue;
            }
            tmp.push_back(s[i]);
            int curr = count ;
            count += (s[i] == '(' ? +1 : -1) ;
            hlpr(i+1,tmp,s,count );
            count = curr ; 
            tmp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        string tmp ;
        hlpr(0,tmp,s,0);
    return vector<string>(ans.begin(), ans.end());
    }
};