class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {    int sz = nums.size();
        vector<int> v(n);
        int last = 0;
        v[0] = 0;
        for(int i = 1 ; i < sz ; i++){
            if(nums[i] - nums[i-1] > maxDiff) 
                last = i;
            v[i] = last;
        }
        vector<bool> ans;
        for(auto &q : queries){
            if(v[q[0]] == v[q[1]]) ans.push_back(1);
            else ans.push_back(0);
        }
    return ans;
    }
};