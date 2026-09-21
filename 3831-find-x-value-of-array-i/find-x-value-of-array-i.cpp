class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k,0);
        vector<long long> prv(k,0);
        for(int i = 0 ; i < n ; i++){
            vector<long long> curr(k,0);
            curr[nums[i]%k]++;
            for(int orm = 0 ; orm < k ; orm++){
                int nr = ( (long long) orm * nums[i] ) % k ;
                curr[nr] += prv[orm];
            }
            for(int j = 0 ; j < k ; j++){
                ans[j] += curr[j];
            }
            prv = move(curr);
        }
        return ans;
    }
};