class Solution {
public:
int mask ; 
string s;
    int hlpr(int ix , bool tight , bool LZ){
        if( ix == s.size()) return 1;
        int limit = tight ? s[ix]-'0' : 9;
        int ans  = 0 ;
        for(int d = 0 ; d <= limit ; d++){
            
            if(LZ && d==0) {
                ans += hlpr(ix+1,tight && d==s[ix]-'0' , LZ ); continue; }
            if( (mask & 1<<d) == 0) continue ;
            
                ans += hlpr(ix+1,tight && d==s[ix]-'0', LZ && d==0 );
        }
    return ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        mask = 0 ;
        s = to_string(n);
        for(auto &s : digits) mask = mask | 1<<stoi(s);
        return hlpr(0,1,1)- 1;
    }
};