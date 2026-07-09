class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {    int sz = nums.size();
        unordered_map<int,int> mp;
        int last = 0;
        mp[0] = 0;
        for(int i = 1 ; i < sz ; i++){
            if(nums[i] - nums[i-1] > maxDiff) 
                last = nums[i];
            mp[i] = last;
        }
        vector<bool> ans;
        for(auto q : queries){
            if(mp[q[0]] == mp[q[1]]) ans.push_back(1);
            else ans.push_back(0);
        }
    return ans;
    }
};