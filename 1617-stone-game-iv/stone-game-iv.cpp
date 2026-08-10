class Solution {
public:
vector<int> p;
    bool hlpr(int n ){
        if(n == 0) return 0;
        if(p[n] != -1) return p[n];
        for(int i = 1 ;  i * i <= n ; i++){
            if(!hlpr(n-(i*i))  ) return p[n] =   1;
        }
    return p[n] = 0 ;
    }
    bool winnerSquareGame(int n) {
        p.resize(n+1,-1);
        return hlpr(n);
    }
};