class Solution {
public:
int n;
    bool ok(int mi , vector<int> &can , long long k){
        long long count = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(can[i] >= mi) count += (can[i]/mi);
            if(count >= k) return true;
        }
    return count >= k ;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        n = candies.size();
        int ans = 0,mx ;
        for(int c : candies) {
            mx = max(mx, c);
        }
        long long sum =  accumulate(candies.begin(),candies.end(),0LL);
        int start = 1;
        int last = min<long long>(mx, sum / k);
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