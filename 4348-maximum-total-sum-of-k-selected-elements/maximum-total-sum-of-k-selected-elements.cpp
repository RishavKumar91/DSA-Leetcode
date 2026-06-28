class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        while(k--){
            int x  = nums.back();
            nums.pop_back();
            if(mul>=2) ans += (1LL * mul-- * x);
            else ans += x;
        }
    return ans;
    }
};