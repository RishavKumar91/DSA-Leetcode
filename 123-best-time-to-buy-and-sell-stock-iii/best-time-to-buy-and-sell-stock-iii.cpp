class Solution {
public:
    int n ;
    vector<vector<int>> t,f;
    // int hlpr(vector<int> &p , int sellleft , int i, bool canbuy){
    //     if(sellleft == 0 || i==n ) return 0 ;
    //     if(canbuy){
    //         if( t[sellleft][i] != -1 ) return t[sellleft][i];
    //         int a = max(-p[i] + hlpr(p,sellleft,i+1,0) , hlpr(p,sellleft,i+1,1));
    //         return t[sellleft][i] = a;
    //     }
    //     else{
    //         if( f[sellleft][i] != -1 ) return f[sellleft][i];
    //         return f[sellleft][i] = 
    //             max(p[i]+  hlpr(p,sellleft-1,i+1,1) , hlpr(p,sellleft,i+1,0)) ;
    //     }
        
        
    // }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        t.resize(3 , vector<int> (n+1,0));
        f.resize(3 , vector<int> (n+1,0));
        for(int sellleft = 1 ; sellleft <= 2 ; sellleft++){
            for(int i = n-1 ; i >= 0 ; i--){
                t[sellleft][i] = max(-prices[i] + f[sellleft][i+1] , t[sellleft][i+1]);
                f[sellleft][i] = max(prices[i] + t[sellleft-1][i+1] , f[sellleft][i+1]);
            }
        }
        return t[2][0];
    }
};