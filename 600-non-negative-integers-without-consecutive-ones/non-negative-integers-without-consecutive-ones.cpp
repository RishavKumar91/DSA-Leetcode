class Solution {
public:
    string s ;
    vector<vector<vector<int>>> dp ; 
    int hlpr(int ix , bool tight , bool prv1){
        if(ix == s.size()) return 1;
        if( dp[ix][tight][prv1] != -1 ) return dp[ix][tight][prv1] ;
        int limit = tight ? s[ix]-'0' : 1 ;
        int ans = 0 ;
        for(int d = 0 ; d <= limit ; d++){
            if(prv1 && d) continue;
            bool newtight = tight && d == limit ;
            ans += hlpr(ix+1,newtight,d);
        }
    return dp[ix][tight][prv1] = ans ;
    }
    int findIntegers(int n) {
        s = bitset<32>(n).to_string();
        // int ix_of_first_1 = s.find('1');
        // s = s.substr(ix_of_first_1);
        dp.resize(s.size()+1,vector<vector<int>> (2,vector<int> (2,-1)));
        return hlpr(0,1,0);
    }
};