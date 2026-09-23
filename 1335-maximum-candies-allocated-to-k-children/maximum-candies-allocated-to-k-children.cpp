class Solution {
public:
int n;
    bool ok(int mi , vector<int> &can , long long k){
        long long count = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(can[i] >= mi) count += (can[i]/mi);
        }
    return count >= k ;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        n = candies.size();
        int ans = 0 ;
        int start = 1  , last = *max_element(candies.begin() , candies.end());
        while(start <= last){
            int mi = start + (last-start)/2;
            if(ok(mi,candies,k)){
                ans = mi ;
                start = mi + 1;
            } else{
                last = mi - 1;
            }
        }
    return ans;
    }
};