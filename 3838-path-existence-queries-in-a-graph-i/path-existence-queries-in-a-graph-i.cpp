class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {    int sz = nums.size();
        // vector<int> v(n);
        int prv = nums[0];
        int last = 0;
        nums[0] = 0;
        for(int i = 1 ; i < sz ; i++){
            int curr = nums[i];
            if( curr - prv > maxDiff) 
                last = i;
            prv = curr ;
            nums[i] = last;
        }
        vector<bool> ans;
        for(auto &q : queries){
            if(nums[q[0]] == nums[q[1]]) ans.push_back(1);
            else ans.push_back(0);
        }
    return ans;
    }
};