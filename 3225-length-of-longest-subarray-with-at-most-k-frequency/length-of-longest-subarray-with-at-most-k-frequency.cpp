class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int j = 0 , i = 0 ,n = nums.size() , ans = 0 , culprit = 0 ;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]] == k+1 ){
                culprit++;
            }
            if(culprit){
                mp[nums[i]]--;
                if(mp[nums[i]] == k){
                    culprit--;
                }
            i++;
            }
            ans = max(ans,j-i+1);
        j++;
        }
    return ans;
    }
};