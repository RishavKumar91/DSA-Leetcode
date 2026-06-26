class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        mp[0] = 1 ;
        long long ans = 0;
        long long frq = 0;
        int lft = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == target){
                lft += mp[frq];
                frq++;
            }
            else {
                frq--;
                lft -= mp[frq];
            }
            ans += lft;
            mp[frq]++;
        }
    return ans;
    }
};