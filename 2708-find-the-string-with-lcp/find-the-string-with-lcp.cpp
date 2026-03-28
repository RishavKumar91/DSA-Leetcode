class Solution {
public:
    vector<vector<int>> chck(string s){
        int n = s.size();
        vector<vector<int>> lcp(n,vector<int> (n,0));
        for(int i = 0;i<n;i++){
            lcp[i][n-1] = s[i] == s[n-1] ? 1 : 0 ;
        }
        for(int j = 0 ;j<n;j++){
            lcp[n-1][j] = s[j] == s[n-1] ? 1 : 0 ;
        }
        for(int i = n-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                lcp[i][j] = s[i]==s[j] ? 1+lcp[i+1][j+1] : 0 ;
            }
        }
    return lcp;
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s = "";
        for(int i = 0;i<n;i++) s.push_back('$');
        
        for(int i  = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(lcp[j][i]>=1) { s[i] = s[j];  break; }
            }
            if(s[i]=='$'){
                vector<bool> done(26,0);
                for(int ix = 0;ix<i;ix++){
                    done[s[ix] - 'a'] = 1;
                }
                for(int ix= 0 ;ix<26;ix++){
                    if(done[ix]==0) { s[i]=ix+'a' ; break;}
                }
            }
        if(s[i]=='$') return "";
        }
    return chck(s) == lcp ? s : "";
    }
};