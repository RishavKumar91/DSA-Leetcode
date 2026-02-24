class Solution {
public:
    int maxProfit(vector<int>& prices) {             // its a fucking dp question thus the tabulation
       // int n = prices.size();
       // vector<int> v(n,0);
        int minn = prices[0];
        int ans = 0;
        int now=0; 
        for(int i =1;i<prices.size();i++){
            if(prices[i]>minn) now = prices[i] - minn;
            ans = max(ans,now);
            if(prices[i]<minn) minn = prices[i];
        }
        // int ans = 0;
        // for(int i =0;i<n;i++){
        //     ans = max(v[i],ans);
        // }
    return ans;
    }
};