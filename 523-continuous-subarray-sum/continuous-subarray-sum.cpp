class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size() , sum = 0 ;
        mp[0] = -1;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            if(mp.count(sum%k) ){
                if(i-mp[sum%k]>1) return 1;
                }
            else mp[sum%k] = i;
        }
    return 0;
    }
};