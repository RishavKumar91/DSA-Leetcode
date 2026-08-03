class Solution {
public:
int n ;
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        n = nums.size();
        int j = 0 , i = 0 , ans = 0 , ni = 0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
                ni = i;
            }
            while(mp[nums[i]] > 1){
                mp[nums[i]]--;
                i++;
            }
            if(mp.size() == k ) ans += (1+i-ni);
        j++;
        }
        return ans ;
    }
};