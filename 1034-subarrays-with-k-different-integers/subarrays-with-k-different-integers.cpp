class Solution {
public:
int n ;
    int sub(vector<int>& nums, int k){
        int j = 0 , i = 0 , ans = 0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            ans += (j-i+1);
        j++;
        }
    return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        n = nums.size();
        return sub(nums,k) - sub(nums,k-1);
    }
};