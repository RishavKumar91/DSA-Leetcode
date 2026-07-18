class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n = nums.size();
        unordered_set<int> st;
        vector<int> ans;
        for(int i = 0 ; i< n ; i++ ) st.insert(nums[i]);
        for(int i = 1 ; i <= n ; i++) if(st.count(i) == 0 ) ans.push_back(i);
        return ans;
    }
};