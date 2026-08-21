class Solution {
public:
typedef long long ll;
int n ;
    bool ok(vector<int> &coins , ll &mi , int &k){
        ll count = 0 ;
        for(int mask = 1 ; mask < (1<<n) ; mask++){
            ll setbitcount = 0 , lcm = 1;
            for(int i = 0 ; i < n ;i++){
                if(mask & 1<<i){
                    setbitcount++;
                    lcm = lcm * coins[i] / __gcd(lcm,1LL * coins[i]);
                }
            }
            if(setbitcount & 1) count += mi/lcm;   // odd
            else count -= mi/lcm ;
        }
    return count >= k ;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        n = coins.size();
        ll start = 0 , last = 1LL *  k *  *min_element(coins.begin() , coins.end());
        ll ans = -1;
        while(start <= last){
            ll mi = start + (last - start)/2;
            if(ok(coins,mi,k)){
                ans = mi ;
                last = mi-1;
            }
            else{
                start = mi+1;
            }
        };
    return ans;
    }
};