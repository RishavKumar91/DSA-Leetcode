class Solution {
public:
int mask ; 
string s;
vector<vector<vector<int>>> dp ; 
    int hlpr(int ix , bool tight , bool LZ){
        if( ix == s.size()) return 1;
        if( dp[ix][tight][LZ] != -1 ) return dp[ix][tight][LZ] ;
        int limit = tight ? s[ix]-'0' : 9;
        int ans  = 0 ;
        for(int d = 0 ; d <= limit ; d++){
            
            if(LZ && d==0) {
                ans += hlpr(ix+1,tight && d==s[ix]-'0' , LZ ); continue; }
            if( (mask & 1<<d) == 0) continue ;
            
                ans += hlpr(ix+1,tight && d==s[ix]-'0', LZ && d==0 );
        }
    return dp[ix][tight][LZ] =  ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        mask = 0 ;
        s = to_string(n);
        for(auto &s : digits) mask = mask | 1<<stoi(s);
        dp.resize(s.size()+1,vector<vector<int>> (2,vector<int> (2,-1)));

        return hlpr(0,1,1)- 1;
    }
};