class Solution {
public:
int n ;
vector<int> p;
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        p.resize(n+1,0);
        p[n] = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            int t1 = stoneValue[i] - p[i+1];
            int t2 = i+1 < n ? stoneValue[i] + stoneValue[i+1] - p[i+2] : INT_MIN;
            int t3 = i+2 < n ? stoneValue[i] + stoneValue[i+1] +stoneValue[i+2] - p[i+3] : INT_MIN;
            p[i] = max({t1,t2,t3});
        }
        int ans =  p[0]  ;


        if(ans > 0) return "Alice";
        else if(ans == 0) return "Tie";
        else return "Bob";
    }
};