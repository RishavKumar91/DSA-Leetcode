class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n-3 ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1 ; j < n-2 ; j++){
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                for(int k = j + 1 ; k < n-1 ; k++ ) {
                    if (k > j+1 && nums[k] == nums[k-1]) continue;
                    for(int l = k+1 ; l < n ; l++){
                        if (l > k+1 && nums[l] == nums[l-1]) continue;
                        if(0LL + nums[i] + nums[j] + nums[k]+nums[l] == target) 
                        ans.insert({nums[i],nums[j],nums[k],nums[l]});
                    }
                }
            }
        }
        vector<vector<int>> last ;
        for(auto &it : ans){
            last.push_back(it);
        }
    return last;
    }
};