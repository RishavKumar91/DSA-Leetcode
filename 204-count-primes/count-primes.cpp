class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n+1,1);
        prime[0] = 0;
        if(prime.size() >= 2) prime[1] = 0;
        for(int i = 2 ; i*i <=n;i++){
            if(prime[i] == 1){
                for(int j = i*i ; j<= n ; j+=i){
                    prime[j] = 0 ;
                }
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(prime[i] == 1) ans++;
        }
    return ans;
    }
};