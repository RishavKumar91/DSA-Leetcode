class Solution {
public:
vector<int> pr;
int n ;
vector<vector<int>> p;
    int hlpr(vector<int> &s , int start , int last){
        if(start >= last) return 0;
        int ans = 0 ;
        if(p[start][last] != -1) return p[start][last];
        for(int i = start ; i < last ; i++){
            int lft   = pr[i] -  (start == 0 ? 0 : pr[start-1]) ;
            int right = pr[last] - pr[i];
            if(lft < right){
                ans = max(ans,lft + hlpr(s,start,i));
            }
            else if(right < lft ){
                ans = max(ans,right + hlpr(s,i+1,last));
            }
            else{
                ans = max(ans,lft + hlpr(s,start,i));
                ans = max(ans,right + hlpr(s,i+1,last));
            }
        }
    return p[start][last] = ans;
    }
    int stoneGameV(vector<int>& s) {
        n = s.size();
        pr.resize(n , 0);
        p.resize(n+1,vector<int> (n+1,-1));
        pr[0] = s[0];
        for(int i = 1 ; i < n ; i++) pr[i] = pr[i-1] + s[i];
        return hlpr(s,0,n-1);
    }
};