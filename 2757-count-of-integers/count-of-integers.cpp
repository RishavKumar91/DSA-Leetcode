class Solution {
public:
vector<vector<vector<int>>> dp ; 
int M = 1e9+7;
    string decOne(string s) {

    int i = s.size() - 1;

    while(s[i] == '0') {
        s[i] = '9';
        i--;
    }

    s[i]--;

    return s;
}
    int hlpr(string &s , int ix , bool tight, int sum, int min_sum, int max_sum){
        if(ix == s.size()){
            return (sum <= max_sum && sum >= min_sum) ;
        }
        if( dp[ix][tight][sum] != -1 ) return dp[ix][tight][sum] ;
        int limit = tight ? s[ix]-'0' : 9;
        long long ans = 0 ;
        for(int d = 0 ; d <= limit ; d++){
            int ntight = tight && d == s[ix]-'0';
            ans += hlpr(s,ix+1,ntight, sum + d,min_sum,max_sum);
        }
    return dp[ix][tight][sum] = ans%M;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        num1 = decOne(num1);
        dp.assign(num2.size()+1,vector<vector<int>> (2,vector<int> (500,-1)));
        int a1 = hlpr(num2,0,1,0,min_sum,max_sum) ;
        dp.assign(num1.size()+1,vector<vector<int>> (2,vector<int> (500,-1)));
        int a2 =  hlpr(num1,0,1,0,min_sum,max_sum);
        return (a1 - a2 + M) % M ;
    }
};