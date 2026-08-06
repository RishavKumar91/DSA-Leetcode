class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0 ;
        long long  i = 0 , n = nums.size() , sum = 0 ;
        unordered_map<int,int> mp;
        for(int j = 0 ;  j < n ; j++){
            sum += nums[j];
            mp[nums[j]]++;
            if(mp.size() == k) ans = max(sum,ans);

            if(j-i+1 == k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
        }
    return ans;
    }
};